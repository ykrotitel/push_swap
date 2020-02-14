# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/02/14 21:39:12 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =  push_swap.c  ft_putstr.c ft_atoi.c first_list.c push_a_b.c swap_a_b.c

all:
	@gcc -o checker $(SOURCES) -I lib_push.h

fclean:
	@rm -rf checker

main: all
	./checker
