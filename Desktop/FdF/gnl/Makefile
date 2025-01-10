# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 13:33:33 by natrodri          #+#    #+#              #
#    Updated: 2024/11/21 13:48:22 by natrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FLAGS = -Wall -Werror -Wextra

FUNCTIONS = get_next_line.c get_next_line_utils.c

OBJECTS=$(FUNCTIONS:.c=.o)

BONUS_OBJ=$(BONUS_FCT:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

.c.o:
	cc $(FLAGS) -c $< -o $@

BONUS_OBJ: $(BONUS_FCT)
	@cc -Wall -Wextra -Werror -c $(BONUS_FCT) -o $(BONUS_OBJ)

bonus: $(BONUS_OBJ) $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
