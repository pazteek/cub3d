# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 02:50:22 by gbabeau           #+#    #+#              #
#    Updated: 2020/01/30 19:00:15 by gbabeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
DOS = ft_printf
SRCS = ft_printf/ft_compare_c_to_s.c ft_printf/error.c ft_printf/ft_conversion_printf.c ft_printf/ft_final_flags.c ft_printf/ft_flags.c ft_printf/ft_flags_0.c ft_printf/ft_flags_c.c ft_printf/ft_flags_modif.c ft_printf/ft_flags_tiret.c ft_printf/ft_point.c ft_printf/ft_putnbr_base.c ft_printf/ft_str_flags.c ft_printf/print.c ft_printf/error.c ft_printf/variable_c_p.c ft_printf/printf_insc.c

OBJ = $(SRCS:$(DOS)/%.c=$(DOS)/%.o)
HEAD = headers
CFLAGS = -Wall -Werror -Wextra -I$(HEAD)
CC = gcc
OBJ_C = libft/srcs/ft_atoi.o libft/srcs/ft_bzero.o libft/srcs/ft_calloc.o libft/srcs/ft_isalnum.o libft/srcs/ft_isalpha.o libft/srcs/ft_isascii.o libft/srcs/ft_isdigit.o libft/srcs/ft_isprint.o libft/srcs/ft_itoa.o libft/srcs/ft_memccpy.o libft/srcs/ft_memchr.o libft/srcs/ft_memcmp.o libft/srcs/ft_memcpy.o libft/srcs/ft_memmove.o libft/srcs/ft_memset.o libft/srcs/ft_putchar_fd.o libft/srcs/ft_putendl_fd.o libft/srcs/ft_putnbr_fd.o libft/srcs/ft_putstr_fd.o libft/srcs/ft_split.o libft/srcs/ft_strchr.o libft/srcs/ft_strdup.o libft/srcs/ft_strjoin.o libft/srcs/ft_strlcat.o libft/srcs/ft_strlcpy.o libft/srcs/ft_strlen.o libft/srcs/ft_strmapi.o libft/srcs/ft_strncmp.o libft/srcs/ft_strnstr.o libft/srcs/ft_strrchr.o libft/srcs/ft_strtrim.o libft/srcs/ft_substr.o libft/srcs/ft_tolower.o libft/srcs/ft_toupper.o libft/srcs/ft_convert_base.o libft/srcs/ft_convert_base2.o libft/srcs/ft_convert_base_p.o libft/srcs/ft_convert_base_p2.o libft/srcs/ft_uitoa.o libft/srcs/ft_ultoa.o

all:  $(NAME)

$(NAME): $(OBJ)
		 Make -C libft
		ar rcs $(NAME)  $(OBJ) $(OBJ_C)

clean :
	Make -C libft clean
	rm -f $(OBJ) $(OBJ_C)
fclean : clean
		Make -C libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean r e

