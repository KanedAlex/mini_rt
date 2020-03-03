# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alienard <alienard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 18:51:33 by alienard          #+#    #+#              #
#    Updated: 2020/02/25 21:38:49 by alienard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

SRCS =		./ft_calloc.c \
			./ft_swap.c \
			./ft_isdigit.c \
			./ft_memcmp.c \
			./ft_strchr.c \
			./ft_strlen.c \
			./ft_tolower.c \
			./ft_atoi.c \
			./ft_atof.c \
			./ft_isalnum.c \
			./ft_isnum.c \
			./ft_isprint.c \
			./ft_memcpy.c \
			./ft_strncmp.c \
			./ft_toupper.c \
			./ft_isalpha.c \
			./ft_memccpy.c \
			./ft_memmove.c \
			./ft_strlcat.c \
			./ft_strnstr.c \
			./ft_bzero.c \
			./ft_isascii.c \
			./ft_isspace.c \
			./ft_memchr.c \
			./ft_memset.c \
			./ft_strlcpy.c \
			./ft_strrchr.c \
			./ft_strdup.c \
			./ft_calloc.c \
			./ft_itoa.c \
			./ft_substr.c \
			./ft_strjoin.c \
			./ft_split.c \
			./ft_strtrim.c \
			./ft_strmapi.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_lstnew_bonus.c \
			./ft_lstadd_front_bonus.c \
			./ft_lstsize_bonus.c \
			./ft_lstlast_bonus.c \
			./ft_lstadd_back_bonus.c \
			./ft_lstdelone_bonus.c \
			./ft_lstclear_bonus.c \
			./ft_lstiter_bonus.c \
			./ft_lstmap_bonus.c \
			./ft_printf.c \
			./ft_padding.c \
			./ft_preci.c \
			./ft_conv.c \
			./ft_conv_2.c \
			./ft_putnbr_base.c \
			./ft_len_hexa.c \
			./get_next_line_bonus.c \
			./get_next_line_utils_bonus.c

OBJS = 		$(SRCS:.c=.o)

CC =		gcc

RM = 		rm -f

AR = 		ar rc

HEADER = 	./

CFLAGS =	-Wall -Wextra -Werror -ofast

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c $< -I $(HEADER) -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		re all clean fclean
