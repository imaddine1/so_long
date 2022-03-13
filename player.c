/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:37:07 by iharile           #+#    #+#             */
/*   Updated: 2022/03/13 12:17:43 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_img *c, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(c->mlx, path, &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, c->x_player, c->y_player);
	c->img = img;
}

int	move_isvalid(t_img *c, char **str, char ch)
{
	int	x_pos;
	int	y_pos;

	x_pos = c->x_player / 50;
	y_pos = c->y_player / 50;
	if (ch == 'w')
		if (str[y_pos - 1][x_pos] == '0' || str[y_pos - 1][x_pos] == 'C')
			return (1);
	else if (ch == 's')
		if (str[y_pos + 1][x_pos] == '0' || str[y_pos - 1][x_pos] == 'C')
			return (1);
	return (0);
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
		update (c, "./assets/sprit.xpm");
	}
}
