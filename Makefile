# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/07/17 14:52:11 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SOURCES =		sources/push.c \
				sources/rotate.c \
				sources/reverse_rotate.c \
				sources/second_main.c \
				sources/swap.c \

PUSH_SWAP = sources/make_A_take_MinMidMax.c

CHECKER = sources/first_main.c

INCLUDES = includes/lib_push.h \

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))



all: $(OBJECTS)
	@make -C libft re
	@gcc -o push_swap $(SOURCES) $(PUSH_SWAP) -I $(INCLUDES) libft/libft.a
	@gcc -o checker $(SOURCES) $(CHECKER) -I $(INCLUDES) libft/libft.a

%.o: %.c $(INCLUDES)
	
clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean

fclean: clean
	@rm -rf checker
	@rm -rf push_swap
	@make -C libft fclean

re: fclean all

main: all
	./checker

make a: all ps

ps:
	@gcc -g -o push_swap $(FOR_PUSH) -I lib_push.h
