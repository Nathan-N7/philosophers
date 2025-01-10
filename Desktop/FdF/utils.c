/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:46:55 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/08 12:46:59 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	to_walk(int n2, int n1)
{
	if (n2 > n1)
		return (1);
	return (-1);
}

long int	convert_base(char *s)
{
	int			i;
	long int	content;

	i = 0;
	content = 0;
	if (s[0] == '0' && s[1] == 'x')
		i = 2;
	while (s[i] != '\0' && s[i] != '\n')
	{
		content *= 16;
		if (s[i] >= '0' && s[i] <= '9')
			content += (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			content += (s[i] - 'A' + 10);
		else if (s[i] >= 'a' && s[i] <= 'f')
			content += (s[i] - 'a' + 10);
		else
			return (16777215);
		i++;
	}
	return (content);
}
