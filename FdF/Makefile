NAME = fdf.a

FLAGS = -Wall -Werror -Wextra

LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

LIBFT = libft/
GNL = gnl/
LIBX = minilibx-linux/

FUNCTIONS = draw.c ft_bresenham.c ft_window.c matriz.c utils.c ft_free.c
OBJECTS = $(FUNCTIONS:.c=.o)

LIBFT_LIB = $(LIBFT)libft.a
GNL_LIB = $(GNL)get_next_line.a
LIBX_LIB = $(LIBX)libmlx_Linux.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(GNL_LIB) $(LIBX_LIB) $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS) $(LIBFT_LIB) $(GNL_LIB) $(LIBX_LIB)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

$(GNL_LIB):
	$(MAKE) -C $(GNL)

$(LIBX_LIB):
	$(MAKE) -C $(LIBX)

clean:
	@rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(GNL) clean
	$(MAKE) -C $(LIBX) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(GNL) fclean
	$(MAKE) -C $(LIBX) fclean

re: fclean all
