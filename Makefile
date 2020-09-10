# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 18:24:23 by acarlett          #+#    #+#              #
#    Updated: 2020/09/10 16:34:12 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SOURCES =		sources/push.c \
				sources/rotate.c \
				sources/reverse_rotate.c \
				sources/second_main.c \
				sources/swap.c \
				sources/helper.c \
				sources/second_helper.c \
				sources/last_helper.c \
				sources/mini.c \
				sources/another_mini.c \
				sources/new.c \
				sources/two_way_list.c \
				sources/chunk_sort.c \
				sources/free.c \
				sources/min_and_max.c \
				sources/chunk.c \
				sources/take_number_operation.c \
				sources/case_find_place.c \
				sources/chunk_rotate_push.c \
				sources/privet.c \

SOURCES_LIB = 	libft/ft_atoi.c \
				libft/ft_isalpha.c \
				libft/ft_putstr.c \

PUSH_SWAP = 	sources/main_ps.c \

CHECKER =		sources/main_ch.c \

INCLUDES = includes/lib_push.h \

INCLUDES_LIB = includes/libft.h \

OBJECTS = $(patsubst %.c,%.o,$(SOURCES)$(PUSH_SWAP)$(CHECKER)$(SOURCES_LIB))

NAME_P = push_swap

NAME_C = checker

all: $(NAME_P) $(NAME_C)


$(NAME_P): $(OBJECTS)
	make -C libft re
	@echo
	@echo "\033[0;93m     LIBFT COMPILATION ---> \033[1;92mSUCCESS !!!\033[0m"
	@echo
	@cc $(FLAGS) -o $(NAME_P) $(PUSH_SWAP) $(SOURCES) -I $(INCLUDES) libft/libft.a -g
	@rm -rf push_swap.dSYM
	@echo "\033[0;93m   PUSH_SWAR COMPILATION ---> \033[1;92mSUCCESS !!!\033[0m"
	@echo


$(NAME_C): $(OBJECTS)
	@cc $(FLAGS) -o $(NAME_C) $(SOURCES) $(CHECKER) -I $(INCLUDES) libft/libft.a -g
	@rm -rf checker.dSYM
	@echo "\033[0;93m    CHECKER COMPILATION ---> \033[1;92mSUCCESS !!!\033[0m"
	@echo

%.o: %.c $(INCLUDES) $(INCLUDES_LIB)
	cc $(FLAGS) -I $(INCLUDES) $< -c -o $@ -g

clean:
	@rm -rf push_swap.dSYM
	@rm -rf checker.dSYM
	@rm -rf $(OBJECTS)
	@make -C libft clean
	@echo
	@echo "\033[1;31m    ALL OBJECT FILES WAS DELETE\033[0m"
	@echo

fclean: clean
	@rm -rf checker
	@rm -rf push_swap
	@echo "\033[1;31m      BINARY FILES WAS DELETE\033[0m"
	@echo
	@make -C libft fclean

re: fclean all

main: all
	./checker

make a: all ps

ps:
	@gcc -g -o push_swap $(FOR_PUSH) -I lib_push.h
