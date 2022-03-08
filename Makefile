# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 10:37:23 by iharile           #+#    #+#              #
#    Updated: 2022/03/08 12:21:41 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = so_long
FILE = %.ber

SRC = libft/handle_inputs.c libft/ft_split.c \
	validate_inputs.c 
	
OBJ = $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $^ -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)