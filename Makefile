# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alienard <alienard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:51:33 by alienard          #+#    #+#              #
#    Updated: 2020/02/18 21:58:12 by alienard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		miniRT

SRCS =		./ft_mini_rt.c \
			./ft_parsing.c \
			./ft_parsing_2.c \
			./ft_bzero_struct.c \
			./ft_check_parsing.c \
			./ft_check_parsing_2.c \
			./ft_cam.c \
			./ft_light.c \
			./ft_sphere.c \
			./ft_plane.c \
			./ft_square.c \
			./ft_cylinder.c \
			./ft_triangle.c \
			./ft_argb.c \
			./ft_event.c \
			./ft_vectors.c \
			./ft_vectors_2.c \
			./ft_scalar.c \
			./ft_matrix.c \
			./ft_ray.c \
			./ft_ray_2.c \
			./ft_close.c \
			./ft_error.c

OBJS = 		$(SRCS:.c=.o)

CC =		gcc

RM = 		rm -f

AR = 		ar rc

HEADER = 	./

CFLAGS =	-Wall -Wextra -Werror -g

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_MAKE = 	$(MAKE) -C $(LIBPATH)

LIBPATH =	./libft/

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c $< -I $(HEADER) -o $(<:.c=.o)

all:		libft/libft.a $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBPATH)*.a

libmake:
			$(LIBFT_MAKE)

libft/libft.a:		
		make -C $(LIBPATH)


$(LIB):
		make -C libft re

bonus:

clean:
			$(RM) $(OBJS)
			$(LIBFT_MAKE) fclean

fclean:		clean
			$(RM) $(NAME)
			$(LIBFT_MAKE) fclean

re:			fclean all

.PHONY:		re all clean fclean
