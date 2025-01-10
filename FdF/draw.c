/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:45:39 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/09 12:52:13 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projecao_3d(int *x, int *y, int z, t_var *var)
{
	int	x3d;
	int	y3d;

	x3d = (*x - *y) * var->scale;
	y3d = (*x + *y - z) * var->scale * PERSPECTIVE_SCALE;
	*x = x3d + var->offset_x;
	*y = y3d + var->offset_y;
}

void	offscreen_img(t_app *app)
{
	app->img->img = mlx_new_image(app->mlx->ptr, WIDTH, HEIGHT);
	if (app->img->img == NULL)
		return ;
	app->img->data = mlx_get_data_addr(app->img->img, &app->img->bpp,
			&app->img->size_line, &app->img->endian);
	app->img->width = WIDTH;
	app->img->height = HEIGHT;
}

void	draw_x(t_app *app, t_var *var, int x, int y)
{
	int	x1;
	int	y1;
	int	z1;

	if (x < app->matriz->x - 1)
	{
		x1 = x + 1;
		y1 = y;
		z1 = app->matriz->mapa[y][x + 1].altura;
		projecao_3d(&x1, &y1, z1, var);
		var->c0 = app->matriz->mapa[y][x].cor;
		bresenham_image(app->img, *var, x1, y1);
	}
}

void	draw_y(t_app *app, t_var *var, int x, int y)
{
	int	x1;
	int	y1;
	int	z1;

	if (y < app->matriz->y - 1)
	{
		x1 = x;
		y1 = y + 1;
		z1 = app->matriz->mapa[y + 1][x].altura;
		projecao_3d(&x1, &y1, z1, var);
		var->c0 = app->matriz->mapa[y][x].cor;
		bresenham_image(app->img, *var, x1, y1);
	}
}

void	desenhar_mapa(t_app *app)
{
	t_var	var;
	int		z0;
	int		x;
	int		y;

	var.offset_x = app->offset_x;
	var.offset_y = app->offset_y;
	var.scale = app->scale;
	offscreen_img(app);
	y = -1;
	while (++y < app->matriz->y)
	{
		x = -1;
		while (++x < app->matriz->x)
		{
			var.x0 = x;
			var.y0 = y;
			z0 = app->matriz->mapa[y][x].altura;
			projecao_3d(&var.x0, &var.y0, z0, &var);
			draw_x(app, &var, x, y);
			draw_y(app, &var, x, y);
		}
	}
	mlx_put_image_to_window(app->mlx->ptr, app->mlx->win, app->img->img, 0, 0);
	mlx_destroy_image(app->mlx->ptr, app->img->img);
}
