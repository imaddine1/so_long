/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:01:23 by iharile           #+#    #+#             */
/*   Updated: 2022/03/18 12:22:32 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	update_enemy(t_img *c, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(c->mlx, path, &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, c->x_enemy, c->y_enemy);
	c->img_enemy = img;
}

int	move_isvalid_enemy(t_img *c, char **str, char ch)
{
	int	x;
	int	y;

	x = c->x_enemy / 50;
	y = c->y_enemy / 50;
	if (ch == 'w')
		if (str[y - 1][x] == '0' || str[y - 1][x] == 'C'
			|| str[y - 1][x] == 'P')
			return (1);
	if (ch == 's')
		if (str[y + 1][x] == '0' || str[y + 1][x] == 'C'
			|| str[y + 1][x] == 'P')
			return (1);
	if (ch == 'd')
		if (str[y][x + 1] == '0' || str[y][x + 1] == 'C'
			|| str[y][x + 1] == 'P')
			return (1);
	if (ch == 'a')
		if (str[y][x - 1] == '0' || str[y][x - 1] == 'C'
			|| str[y][x - 1] == 'P')
			return (1);
	if (c->nbr_coins == c->counter_coin && (str[y - 1][x] == 'E' || str[y + 1]
		[x] == 'E' || str[y][x - 1] == 'E' || str[y][x + 1] == 'E'))
		exit(1);
	return (0);
}

void	move_up_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 'w'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update_enemy (c, "./assets/green.xpm");
		c->y_enemy -= 50;
		c->y = c->y_enemy;
		c->x = c->x_enemy;
		if (c->str[c->y_enemy / 50][c->x_enemy / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_enemy / 50][c->x_enemy / 50] = '0';
		}
		update_enemy (c, "./assets/enemy.xpm");
		//update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_down_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 's'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update_enemy (c, "./assets/green.xpm");
		c->y_enemy += 50;
		c->y = c->y_enemy;
		c->x = c->x_enemy;
		if (c->str[c->y_enemy / 50][c->x_enemy / 50] == 'C' )
		{
			c->nbr_coins++;
			c->str[c->y_enemy / 50][c->x_enemy / 50] = '0';
		}
		update_enemy (c, "./assets/enemy.xpm");
		//update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_right_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 'd'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update_enemy (c, "./assets/green.xpm");
		c->x_enemy += 50;
		c->y = c->y_enemy;
		c->x = c->x_enemy;
		if (c->str[c->y_enemy / 50][c->x_enemy / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_enemy / 50][c->x_enemy / 50] = '0';
		}
		update_enemy (c, "./assets/enemy.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}

void	move_left_enemy(t_img *c)
{
	if (move_isvalid_enemy(c, c->str, 'a'))
	{
		mlx_destroy_image(c->mlx, c->img);
		update_enemy (c, "./assets/green.xpm");
		c->x_enemy -= 50;
		c->y = c->y_enemy;
		c->x = c->x_enemy;
		if (c->str[c->y_enemy / 50][c->x_enemy / 50] == 'C')
		{
			c->nbr_coins++;
			c->str[c->y_enemy / 50][c->x_enemy / 50] = '0';
		}
		update_enemy (c, "./assets/enemy.xpm");
	//	update_ground(c, ft_itoa(c->nbr_move++));
	}
}

int	next_frame(t_img *c)
{
	if (c->init_enemy == 10000)
	{
		if (move_isvalid_enemy(c, c->str, 'w'))
			move_up_enemy(c);
		else if (move_isvalid_enemy(c, c->str, 's'))
			move_down_enemy(c);
		c->init_enemy = 0;
	}
	else
		c->init_enemy++;
	return (0);
}
