# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/17 13:21:03 by acarlett          #+#    #+#              #
#    Updated: 2020/07/22 18:23:08 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	ft_atoi.c \
			ft_putstr.c \
			ft_isalpha.c \

INCLUDES =	../includes/libft.h \

NAME = libft.a

OBJ = $(patsubst %.c,%.o,$(SOURCES))

all: $(NAME) clean

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c $(INCLUDES)
		@gcc $< -c -o $@

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re