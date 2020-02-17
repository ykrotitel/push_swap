# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/02/15 22:04:33 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =  first_main.c  \
ft_putstr.c \
ft_atoi.c \
second_main.c \
push.c \
swap.c \
rotate.c \
reverse_rotate.c \
ft_isalpha.c

all:
	@gcc -o checker $(SOURCES) -I lib_push.h

fclean:
	@rm -rf checker

main: all
	./checker
