# ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
# include <stdlib.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

# define HEIGHT 1080
# define WIDTH 1920
# define SCALE 10
#define PERSPECTIVE_SCALE 0.5


typedef struct s_window
{
    void *ptr;
    void *win;
} t_window;


typedef struct s_ponto
{
    int	altura;
    long int	cor;
} t_ponto;

typedef struct s_matriz
{
	int	x;
	int	y;
	t_ponto	**mapa;
}	t_matriz;

typedef struct s_image
{
    void    *img;        // Ponteiro para a imagem
    char    *data;       // Dados da imagem (para acesso aos pixels)
    int     width;       // Largura da imagem
    int     height;      // Altura da imagem
    int     bpp;         // Bits por pixel
    int     size_line;   // Tamanho da linha
    int     endian;      // Endianidade dos dados
} t_image;

typedef struct s_app
{
    t_window *mlx;       // Ponteiro para a struct t_window (MLX)
    t_matriz *matriz;    // Ponteiro para a struct t_matriz (mapa de pontos)
    t_image  *img;       // Ponteiro para a struct t_image (imagem offscreen)
} t_app;

int	count_x(char	*str);
int	count_y(int	fd);
t_ponto	*mapa_line(char	*line, int x);
void	creat_matriz(t_matriz *ptr, int fd);
void	free_matriz(t_matriz	*ptr);
long int	convert_base(char *s);
int to_walk(int n2, int n1);
int ft_abs(int n);

#endif
