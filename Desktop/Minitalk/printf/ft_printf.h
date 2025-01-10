/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:48:29 by natrodri          #+#    #+#             */
/*   Updated: 2025/01/10 06:15:04 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		put_hex(unsigned int nbr, char *base);
int		ft_putstr(char *str);
int		put_pointer(void *nbr, char *base);
char	*ft_utoa(unsigned int n);
int		putnbr_u(unsigned int nbr);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif
