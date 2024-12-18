#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int button_press(int keysym, t_window *mlx)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(mlx->ptr, mlx->win);
        mlx_destroy_display(mlx->ptr);
        free(mlx->ptr);
        exit(0);
    }
    return (0);
}

int event_close(t_window *mlx)
{
    mlx_destroy_window(mlx->ptr, mlx->win);
    mlx_destroy_display(mlx->ptr);
    free(mlx->ptr);
    exit(0);
}

void projecao_3d(int *x, int *y, int z, int offset_x, int offset_y)
{
    int x3d;
    int y3d;

    x3d = (*x - *y) * SCALE;
    y3d = (*x + *y - z) * SCALE * PERSPECTIVE_SCALE;

    *x = x3d + offset_x;
    *y = y3d + offset_y;
}

void bresenham_image(t_image *img, int x0, int y0, int x1, int y1, long cor)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        // Verificar se o ponto (x0, y0) está dentro dos limites da imagem
        if (x0 >= 0 && x0 < img->width && y0 >= 0 && y0 < img->height)
        {
            // Acessar o pixel na posição (x0, y0) no buffer de dados da imagem
            int pixel_index = (y0 * img->size_line) + (x0 * (img->bpp / 8));

            // Definir a cor do pixel (convertendo para formato de cor adequado)
            *(unsigned int *)(img->data + pixel_index) = cor;
        }

        // Se chegou ao ponto final, parar
        if (x0 == x1 && y0 == y1)
            break;

        // Calcular o erro e atualizar as coordenadas
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void desenhar_mapa(t_app *app)
{
    int offset_x = (WIDTH - app->matriz->x * 10) / 2;
    int offset_y = (HEIGHT - app->matriz->y * 10) / 2;

    // Criar imagem offscreen
    app->img->img = mlx_new_image(app->mlx->ptr, WIDTH, HEIGHT);
    app->img->data = mlx_get_data_addr(app->img->img, &app->img->bpp, &app->img->size_line, &app->img->endian);
    app->img->width = WIDTH;
    app->img->height = HEIGHT;

    int x, y;
    for (y = 0; y < app->matriz->y; y++)
    {
        for (x = 0; x < app->matriz->x; x++)
        {
            int x0 = x;
            int y0 = y;
            int z0 = app->matriz->mapa[y][x].altura;

            projecao_3d(&x0, &y0, z0, offset_x, offset_y);

            // Linha horizontal
            if (x < app->matriz->x - 1)
            {
                int x1 = x + 1;
                int y1 = y;
                int z1 = app->matriz->mapa[y][x + 1].altura;
                projecao_3d(&x1, &y1, z1, offset_x, offset_y);
                bresenham_image(app->img, x0, y0, x1, y1, app->matriz->mapa[y][x].cor);
            }

            // Linha vertical
            if (y < app->matriz->y - 1)
            {
                int x1 = x;
                int y1 = y + 1;
                int z1 = app->matriz->mapa[y + 1][x].altura;
                projecao_3d(&x1, &y1, z1, offset_x, offset_y);
                bresenham_image(app->img, x0, y0, x1, y1, app->matriz->mapa[y][x].cor);
            }
        }
    }

    // Exibir a imagem offscreen na janela
    mlx_put_image_to_window(app->mlx->ptr, app->mlx->win, app->img->img, 0, 0);

    // Limpeza da imagem após exibição
    mlx_destroy_image(app->mlx->ptr, app->img->img);
}


int main()
{
    t_app app;
    t_matriz matriz;
    t_image img;

    app.mlx = (t_window *)malloc(sizeof(t_window));
    app.matriz = &matriz;
    app.img = &img;

    app.mlx->ptr = mlx_init();
    app.mlx->win = mlx_new_window(app.mlx->ptr, WIDTH, HEIGHT, "Mapa FDF");

    int fd = open("test_maps/t2.fdf", O_RDONLY);
    if (fd < 0)
        return (-1);

    matriz.x = count_x(get_next_line(fd));
    matriz.y = count_y(fd);
    close(fd);

    fd = open("test_maps/t2.fdf", O_RDONLY);
    creat_matriz(&matriz, fd);
    close(fd);

    desenhar_mapa(&app);

    mlx_key_hook(app.mlx->win, button_press, app.mlx);
    mlx_hook(app.mlx->win, 17, 0, event_close, app.mlx);
    mlx_loop(app.mlx->ptr);

    free_matriz(&matriz);
    free(app.mlx); // Não esquecer de liberar o ponteiro da janela (se alocado dinamicamente)
    return (0);
}


