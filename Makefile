# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:04:03 by jbouyer           #+#    #+#              #
#    Updated: 2021/12/21 08:04:11 by jbouyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c ft_printf.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c printf.h
	 gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : 
	rm -rf $(NAME) $(OBJS)

re : fclean all
	
