# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 17:47:48 by dwalda-r          #+#    #+#              #
#    Updated: 2018/12/28 16:26:50 by dwalda-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = libft.h

src = $(wildcard *.c)
obj = $(src:.c=.o)

all: $(NAME)

$(obj): $(src)
	gcc -c -Wall -Wextra -Werror $(src)

$(NAME): $(obj)
	ar rc $(NAME) $(obj)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all
