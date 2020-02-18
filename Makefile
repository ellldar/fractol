NAME = fractol
SRC = fractol.c
HDR = -I/includes
FLGS = -Wall -Werror -Wextra
SANIT = -fsanitize=address
LIBFT_DIR = libft-wip-version
LIBX_DIR = minilibx_macos
LIBS = -L ./$(LIBFT_DIR) -lft -L ./$(LIBX_DIR) -lmlx
LIBFT = $(LIBFT_DIR)/libft.a
LIBX = $(LIBX_DIR)/libmlx.a
MLX = -framework OpenGL -framework AppKit

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(LIBX) $(INPUT)
	gcc -o $(NAME) $(SRC) $(HDR) $(LIBS) $(MLX)

$(LIBFT):
	git submodule update --init
	@make -C $(LIBFT_DIR)

$(LIBX):
	@make -C $(LIBX_DIR)

debug:
	gcc -o $(NAME) $(SRCS) $(HDR) $(LIBS) $(MLX) -g
	lldb $(NAME) -- $(INPUT)

sanit:
	gcc -o $(NAME) $(SRCS) $(HDR) $(LIBS) $(MLX) $(SANIT) -g
	./$(NAME) $(INPUT)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(LIBX)
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(NAME).h
