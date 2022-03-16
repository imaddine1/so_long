/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:37:07 by iharile           #+#    #+#             */
/*   Updated: 2022/03/16 11:48:59 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *str)
{
	int	lengh;

	lengh = ft_strlen(str);
	write(2, str, lengh);
	exit(1);
}

void	move_up(t_img *c)
{

	if (move_isvalid(c, c->str, 'w'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->y_player -= 50;
		c->y = c->y_player;
		c->x = c->x_player;
		if (c->str[c->y_player / 50][c->x_player / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_player / 50][c->x_player / 50] = '0';
		}
		update (c, "./assets/sprit.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_down(t_img *c)
{
	int	x;

	x = 0;
	if (move_isvalid(c, c->str, 's'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->y_player += 50;
		c->y = c->y_player;
		c->x = c->x_player;
		if (c->str[c->y_player / 50][c->x_player / 50] == 'C' )
		{
			c->nbr_coins++;
			c->str[c->y_player / 50][c->x_player / 50] = '0';
		}
		update (c, "./assets/sprit.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_right(t_img *c)
{
	if (move_isvalid(c, c->str, 'd'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->x_player += 50;
		c->y = c->y_player;
		c->x = c->x_player;
		if (c->str[c->y_player / 50][c->x_player / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_player / 50][c->x_player / 50] = '0';
		}
		update (c, "./assets/sprit.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_left(t_img *c)
{
	if (move_isvalid(c, c->str, 'a'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update (c, "./assets/green.xpm");
		c->x_player -= 50;
		c->y = c->y_player;
		c->x = c->x_player;
		if (c->str[c->y_player / 50][c->x_player / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_player / 50][c->x_player / 50] = '0';
		}
		update (c, "./assets/sprit.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}