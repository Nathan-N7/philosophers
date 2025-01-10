/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:45:53 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/08 12:45:59 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	verify_draw(t_bresenham var_b, int *err, t_var *var, int *e2)
{
	if (*e2 > -var_b.dy)
	{
		*err -= var_b.dy;
		var->x0 += var_b.sx;
	}
	if (*e2 < var_b.dx)
	{
		*err += var_b.dx;
		var->y0 += var_b.sy;
	}
}

void	bresenham_image(t_image *img, t_var var, int x1, int y1)
{
	t_bresenham	var_b;
	int			err;
	int			e2;
	int			pixel_index;

	var_b.dx = ft_abs(x1 - var.x0);
	var_b.dy = ft_abs(y1 - var.y0);
	var_b.sx = to_walk(x1, var.x0);
	var_b.sy = to_walk(y1, var.y0);
	err = var_b.dx - var_b.dy;
	while (1)
	{
		if (var.x0 >= 0 && var.x0 < img->width && var.y0 >= 0
			&& var.y0 < img->height)
		{
			pixel_index = (var.y0 * img->size_line) + (var.x0 * (img->bpp / 8));
			*(unsigned int *)(img->data + pixel_index) = var.c0;
		}
		if (var.x0 == x1 && var.y0 == y1)
			break ;
		e2 = 2 * err;
		verify_draw(var_b, &err, &var, &e2);
	}
}
