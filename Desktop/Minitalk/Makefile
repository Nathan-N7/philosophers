# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 06:26:06 by natrodri          #+#    #+#              #
#    Updated: 2025/01/10 06:54:08 by natrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTFNAME = libftprintf.a  # Nome da biblioteca de printf

CLIENT= client.c
SERVER= server.c

CLIENT_OBJS= $(CLIENT:.c=.o)
SERVER_OBJS= $(SERVER:.c=.o)

CLIENT_BONUS= client_bonus.c
SERVER_BONUS= server_bonus.c
ATOI = ft_atoi.c

CLIENT_BONUS_OBJS= $(CLIENT_BONUS:.c=.o)
SERVER_BONUS_OBJS= $(SERVER_BONUS:.c=.o)

all: server client

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makeprintf:
	@make -C ./printf
	@cp ./printf/$(PRINTFNAME) .

client: $(CLIENT_OBJS) makeprintf
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(ATOI) $(PRINTFNAME) -o client

server: $(SERVER_OBJS) makeprintf
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(ATOI) $(PRINTFNAME) -o server

client_bonus: $(CLIENT_BONUS_OBJS) makeprintf
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(PRINTFNAME) -o client_bonus

server_bonus: $(SERVER_BONUS_OBJS) makeprintf
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(PRINTFNAME) -o server_bonus

bonus: client_bonus server_bonus

clean:
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	cd ./printf && make clean

fclean: clean
	@rm -f $(PRINTFNAME) client server client_bonus server_bonus
	cd ./printf && make fclean

re: fclean all

