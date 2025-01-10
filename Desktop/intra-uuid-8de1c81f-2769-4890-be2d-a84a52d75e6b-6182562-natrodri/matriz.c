/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:47:11 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/08 12:48:03 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_x(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			i++;
	}
	free (str);
	return (count);
}

int	count_y(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{	
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free (line);
	close(fd);
	return (i + 1);
}

void	populate(t_ponto *linem, char **color_hex, char **num, int x)
{
	int	i;
	int	k;

	i = 0;
	while (num[i] != NULL && i < x)
	{
		k = -1;
		linem[i].altura = ft_atoi(num[i]);
		color_hex = ft_split(num[i], ',');
		if (color_hex != NULL && color_hex[1] != NULL)
			linem[i].cor = convert_base(color_hex[1]);
		else
			linem[i].cor = convert_base("0xAAAAAA");
		while (color_hex[++k] != NULL)
			free(color_hex[k]);
		free (color_hex);
		free (num[i]);
		i++;
	}
	free (num[i]);
	free(num);
}

t_ponto	*mapa_line(char	*line, int x)
{
	char	**num;
	char	**color_hex;
	t_ponto	*linem;
	int		i;

	i = 0;
	color_hex = NULL;
	num = ft_split(line, ' ');
	if (num == NULL)
		return (NULL);
	linem = malloc(sizeof(t_ponto) * x);
	if (linem == NULL)
	{
		i = 0;
		while (num[i] != NULL)
		{
			free (num[i]);
			i++;
		}
		free(num);
		return (NULL);
	}
	populate(linem, color_hex, num, x);
	return (linem);
}

void	creat_matriz(t_matriz *ptr, int fd)
{
	char	*line;
	int		i;

	ptr->mapa = (t_ponto **)malloc(sizeof(t_ponto *) * ptr->y);
	if (ptr->mapa == NULL)
		return ;
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (i < ptr->y)
		{
			ptr->mapa[i] = mapa_line(line, ptr->x);
			if (ptr->mapa[i] == NULL)
			{
				free (line);
				map_error(ptr, i, NULL);
				return ;
			}
		}
		free (line);
		line = get_next_line(fd);
		i++;
	}
}
