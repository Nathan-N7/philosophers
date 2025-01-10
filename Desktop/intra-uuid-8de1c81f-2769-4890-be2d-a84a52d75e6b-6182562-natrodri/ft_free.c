/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:46:09 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/08 12:46:15 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(t_matriz *ptr, int i, char *line)
{
	int	j;

	j = 0;
	free(line);
	while (j < i)
	{
		if (ptr->mapa[j] != NULL)
		{
			free(ptr->mapa[j]);
			ptr->mapa[j] = NULL;
		}
		j++;
	}
	if (ptr->mapa != NULL)
	{
		free(ptr->mapa);
		ptr->mapa = NULL;
	}
}

void	free_matriz(t_matriz	*ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	if (ptr->mapa)
	{
		while (i < ptr->y)
		{
			if (ptr->mapa[i] != NULL)
			{
				free(ptr->mapa[i]);
				ptr->mapa[i++] = NULL;
			}
		}
		free(ptr->mapa);
		ptr->mapa = NULL;
	}
}
