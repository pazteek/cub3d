NAME = Cub3d

SRCS = $(RAY) $(PLAY) $(DIS) $(END) $(BMP) $(DIV) $(IVA) $(IST) srcs/main.c
RAY = srcs/raycasting/raycasting.c srcs/raycasting/rayon.c

PLAY = srcs/act_player/collision.c srcs/act_player/player_move.c srcs/act_player/rot_player.c srcs/act_player/input.c

DIS = srcs/display/display_fc.c  srcs/display/display_wall.c srcs/display/display_sprite.c srcs/display/display_sprite_2.c

END = srcs/end_cub3d/ft_end.c srcs/end_cub3d/error.c

BMP = srcs/bmp/bmp.c

DIV = srcs/divers/complement.c srcs/divers//ft_free.c

IVA = srcs/init_var_struc/check_map.c srcs/init_var_struc/cub3d_init.c srcs/init_var_struc/init_map.c\
srcs/init_var_struc/init_parsing.c srcs/init_var_struc/init_struct_var.c srcs/init_var_struc/init_textur.c

IST = srcs/init_struc/malloc_struc.c

MLX = -lmlx -lm -framework OpenGL -framework AppKit

MLX_L = -L/usr/include -lm -lbsd -lX11 -lXext

BOFT = $(BO:.c=.o)
OBJ = $(SRCS:.c=.o)
HEAD = include
CFLAGS = -Wall -Werror -Wextra -I$(HEAD)
CC = gcc
LIB = ./libft/libft.a

all: $(NAME)
	Make -C libft

$(NAME): $(OBJ)
	Make -C libft
	gcc  $(SRCS) $(CFLAGS) -I./include  $(MLX) $(LIB) -o $(NAME)
clean :
	Make -C libft clean
	rm -f $(OBJ)
fclean : clean
	Make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus  all clean fclean r e

