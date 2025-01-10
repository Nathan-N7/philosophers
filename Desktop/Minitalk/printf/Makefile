# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 13:33:33 by natrodri          #+#    #+#              #
#    Updated: 2025/01/05 11:34:22 by natrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

FUNCTIONS = ft_putchar.c ft_atoi.c ft_putnbr.c ft_strlen.c ft_strchr.c puthex.c putnbr_u.c putpointer.c putstr.c ft_printf.c

OBJECTS=$(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

.c.o:
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
