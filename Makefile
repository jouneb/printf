# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:04:03 by jbouyer           #+#    #+#              #
#    Updated: 2022/01/05 11:58:22 by jbouyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c ft_printf.c ft_putchar.c
OBJS = ${SRCS:.c=.o}

HEADER = printf.h
all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	 gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : 
	rm -rf $(NAME) $(OBJS)

re : fclean all
	
