/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:46:32 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/09 15:52:12 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc_close(int keysym, t_app *app)
{
	if (keysym == 65307)
	{
		free_matriz(app->matriz);
		mlx_destroy_window(app->mlx->ptr, app->mlx->win);
		mlx_destroy_display(app->mlx->ptr);
		free(app->mlx->ptr);
		free(app->mlx);
		exit(0);
	}
	return (0);
}

int	key_press(int keysym, t_app *app)
{
	if (keysym == 65307)
		esc_close(keysym, app);
	if (keysym == 119)
		app->offset_y -= 10;
	else if (keysym == 115)
		app->offset_y += 10;
	else if (keysym == 97)
		app->offset_x -= 10;
	else if (keysym == 100)
		app->offset_x += 10;
	else if (keysym == KEY_PLUS)
	{
		if (app->scale > 1)
			app->scale -= 1;
	}
	else if (keysym == KEY_MINUS)
		app->scale += 1;
	desenhar_mapa(app);
	return (0);
}

int	event_close(t_app *app)
{
	free_matriz(app->matriz);
	mlx_destroy_window(app->mlx->ptr, app->mlx->win);
	mlx_destroy_display(app->mlx->ptr);
	free(app->mlx->ptr);
	free(app->mlx);
	exit(0);
	return (0);
}

void	variable_value(t_app *app, t_matriz *matriz, t_image *img)
{
	app->mlx = (t_window *)malloc(sizeof(t_window));
	if (app->mlx == NULL)
		return ;
	app->matriz = matriz;
	app->img = img;
	app->mlx->ptr = mlx_init();
	if (!app->mlx)
		return ;
	app->scale = 10;
	app->mlx->win = mlx_new_window(app->mlx->ptr, WIDTH, HEIGHT, "Mapa FDF");
	app->offset_x = (WIDTH - (matriz->x * app->scale)) / 2;
	app->offset_y = (HEIGHT - (matriz->y * app->scale * PERSPECTIVE_SCALE)) / 2;
	if (app->offset_x < 0)
		app->offset_x = 0;
	if (app->offset_y < 0)
		app->offset_y = 0;
}

int	main(void)
{
	t_app		app;
	t_matriz	matriz;
	t_image		img;
	int			fd;

	fd = open("test_maps/t2.fdf", O_RDONLY);
	if (fd < 0)
		return (-1);
	matriz.x = count_x(get_next_line(fd));
	matriz.y = count_y(fd);
	close(fd);
	variable_value(&app, &matriz, &img);
	fd = open("test_maps/t2.fdf", O_RDONLY);
	if (fd < 0)
		return (-1);
	creat_matriz(&matriz, fd);
	if (!matriz.mapa)
		return (-1);
	close(fd);
	desenhar_mapa(&app);
	mlx_key_hook(app.mlx->win, key_press, &app);
	mlx_hook(app.mlx->win, 17, 0, event_close, &app);
	mlx_loop(app.mlx->ptr);
	return (0);
}
