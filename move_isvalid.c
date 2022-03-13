/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_isvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:23:37 by iharile           #+#    #+#             */
/*   Updated: 2022/03/13 17:11:26 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_coin(char **str)
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
			if (str[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
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
	if (c->nbr_coins == c->counter_coin && (str[y - 1][x] == 'E' || str[y + 1]
		[x] == 'E' || str[y][x - 1] == 'E' || str[y][x + 1] == 'E'))
		exit(1);
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
	return (0);
}
