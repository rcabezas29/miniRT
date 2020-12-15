# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 11:54:21 by rcabezas          #+#    #+#              #
#    Updated: 2020/12/15 17:20:07 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    LIBS := -lm -lbsd -lX11 -lXext
    MLX = mlx_linux/libmlx.a
    MINILIBX = mlx_linux
    INCLUDES = -I/usr/include -I. -g3 -Iincludes/ -I $(MINILIBX) -I $(LIBFT)
endif

ifeq ($(UNAME_S), Darwin)
    LIBS := -lz -framework OpenGL -framework Appkit
    MLX = mlx_ios/libmlx.dylib
    MINILIBX = mlx_ios
    INCLUDES = -I/usr/include -I. -Iincludes/ -I $(MINILIBX) -I $(LIBFT)
endif

NAME = miniRT

CFLAGS = gcc -Werror -Wextra -Wall -g

SRCS_MRT = 	minirt.c vector_operations.c handle_errors.c \
			parse_file.c parse_objects.c parse_utils.c colors.c \
			raytrace.c sphere.c plane.c square.c cylinder.c \
			triangle.c light.c camera.c keyhook.c bmp.c shadows.c \
			move_objs.c

SRCS = $(addprefix srcs/, $(SRCS_MRT))

OBJS = $(SRCS:.c=.o)

LIBFT = libft

RM = rm -rf

LIB = $(addprefix $(INCLUDES_PATH)/, minirt.h)

all: $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MINILIBX)
	@make -C $(LIBFT)
	@$(CFLAGS) -I $(INCLUDES) $(LIBFT)/libft.a $(MLX) $(OBJS) -o $(NAME)
	@cp $(MLX) ./

%.o: %.c
	@$(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make clean -C ./mlx_linux
	@make clean -C ./mlx_ios
	@make clean -C $(LIBFT)

fclean:			clean
	@$(RM) $(NAME)
	@$(RM) libmlx.a libmlx.dylib
	@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re