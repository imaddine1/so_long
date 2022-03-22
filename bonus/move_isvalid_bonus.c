/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_isvalid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:23:37 by iharile           #+#    #+#             */
/*   Updated: 2022/03/22 17:24:21 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	counter_constraint(char **str, char ch)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ch)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	update_ground(t_img *c, char *number)
{
	void	*img;
	int		white;

	white = 0xFFFFFFFF;
	img = mlx_xpm_file_to_image(c->mlx, "./assets/ground.xpm", &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, 0, 0);
	mlx_destroy_image(c->mlx, c->first_ground);
	mlx_string_put(c->mlx, c->mlx_win, 5, 5, white, number);
	c->first_ground = img;
	free(number);
}

void	update(t_img *c, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(c->mlx, path, &c->w, &c->h);
	mlx_put_image_to_window(c->mlx, c->mlx_win, img, c->x_player, c->y_player);
	c->img = img;
}

int	move_isvalid(t_img *c, char **str, char ch)
{
	int	x;
	int	y;

	x = c->x_player / 50;
	y = c->y_player / 50;
	if (ch == 'w')
		if (str[y - 1][x] == '0' || str[y - 1][x] == 'C'
			|| str[y - 1][x] == 'P' || str[y - 1][x] == 'F')
			return (1);
	if (ch == 's')
		if (str[y + 1][x] == '0' || str[y + 1][x] == 'C'
			|| str[y + 1][x] == 'P' || str[y + 1][x] == 'F')
			return (1);
	if (ch == 'd')
		if (str[y][x + 1] == '0' || str[y][x + 1] == 'C'
			|| str[y][x + 1] == 'P' || str[y][x + 1] == 'F')
			return (1);
	if (ch == 'a')
		if (str[y][x - 1] == '0' || str[y][x - 1] == 'C'
			|| str[y][x - 1] == 'P' || str[y][x - 1] == 'F')
			return (1);
	return (0);
}
