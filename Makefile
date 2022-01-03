# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 11:04:03 by jbouyer           #+#    #+#              #
#    Updated: 2022/01/03 13:04:36 by jbouyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c ft_printf.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	 gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : 
	rm -rf $(NAME) $(OBJS)

re : fclean all
	
