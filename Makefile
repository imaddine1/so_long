# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 10:37:23 by iharile           #+#    #+#              #
#    Updated: 2022/03/17 10:43:12 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

man = mandatory
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BONUS = so_long_bonus
MLX = -lmlx -framework OpenGl -framework AppKit

SRC = libft/handle_inputs.c libft/ft_split.c libft/ft_putnbr.c\
	$(man)/validate_inputs.c $(man)/constraints.c $(man)/so_long.c $(man)/player.c $(man)/move_isvalid.c

SRCB = libft/handle_inputs.c libft/ft_split.c libft/ft_putnbr.c libft/ft_itoa.c\
	 bonus/validate_inputs_bonus.c bonus/constraints_bonus.c bonus/so_long_bonus.c bonus/player_bonus.c bonus/move_isvalid_bonus.c

OBJB = $(SRCB:.c=.o)

OBJ = $(SRC:.c=.o)



all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(MLX) $^ -o $(NAME)

clean :
	rm -rf $(OBJ) $(OBJB)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJB)
	$(CC) $(MLX) $^ -o $(NAME_BONUS)
	

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all