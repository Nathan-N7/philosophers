/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:45:07 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/08 15:47:59 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

# define ESC 65307
# define KEY_PLUS 45 // Código ASCII para '+'
# define KEY_MINUS 61  // Código ASCII para '-'

# define WIDTH 1280
# define HEIGHT 720
# define PERSPECTIVE_SCALE 0.5

typedef struct s_window
{
	void	*ptr;
	void	*win;
}	t_window;

typedef struct s_ponto
{
	int			altura;
	long int	cor;
}	t_ponto;

typedef struct s_matriz
{
	int		x;
	int		y;
	t_ponto	**mapa;
}	t_matriz;

typedef struct s_image
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_app
{
	t_window	*mlx;
	t_matriz	*matriz;
	t_image		*img;
	int			scale;
	int			offset_x;
	int			offset_y;
}	t_app;

typedef struct s_var
{
	long	c0;
	int		x0;
	int		y0;
	int		offset_y;
	int		offset_x;
	int		scale;
}	t_var;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

int		key_press(int keysym, t_app *app);
int		event_close(t_app *app);
void	bresenham_image(t_image *img, t_var var, int x1, int y1);
void	desenhar_mapa(t_app *app);
int		count_x(char	*str);
int		count_y(int fd);
void	creat_matriz(t_matriz *ptr, int fd);
int		ft_abs(int n);
int		to_walk(int n2, int n1);
long	int	convert_base(char *s);
void	free_matriz(t_matriz	*ptr);
void	map_error(t_matriz *ptr, int i, char *line);

#endif
