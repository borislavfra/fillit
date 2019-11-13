# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 17:47:48 by dwalda-r          #+#    #+#              #
#    Updated: 2019/04/22 10:33:25 by dwalda-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = src/
INC_DIR = includes/
LIB_DIR = libft/
LIB_NAME = libft.a
SRCS = *.c
INCS = *.h
OBJ = $(SRCS:.c=.o)
NAME = fillit

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	make -C $(LIB_DIR) $(LIB_NAME)

$(NAME): $(LIB_NAME)
	$(CC) -c $(SRC_DIR)$(SRCS) -I $(INC_DIR) -I $(LIB_DIR) $(FLAGS)
	$(CC) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
