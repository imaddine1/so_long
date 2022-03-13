/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:35 by iharile           #+#    #+#             */
/*   Updated: 2022/03/13 08:43:18 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_image(t_img *c, char **s)
{
	c->mlx = mlx_init();
	c->row = count_line(s);
	c->col = ft_strlen(*s);
	c->mlx_win = mlx_new_window(c->mlx, c->col * 60, c->row * 50, "So_long!");
	c->x = 0;
	c->y = 0;
	c->i = -1;
	c->j = 0;
}

void	initialize(char *path, t_img *coor)
{
	void	*img;

	img = mlx_xpm_file_to_image(coor->mlx, path, &coor->h, &coor->w);
	mlx_put_image_to_window(coor->mlx, coor->mlx_win, img, coor->x, coor->y);
}

void	so_long(char **str)
{
	t_img	coordinate;

	initialize_image(&coordinate, str);
	while (str[++coordinate.i])
	{
		coordinate.j = 0;
		coordinate.x = 0;
		while (str[coordinate.i][coordinate.j])
		{
			if (str[coordinate.i][coordinate.j] != '1')
				initialize("./assets/green.xpm", &coordinate);
			if (str[coordinate.i][coordinate.j] == '1')
				initialize("./assets/ground.xpm", &coordinate);
			else if (str[coordinate.i][coordinate.j] == 'E')
				initialize("./assets/exit.xpm", &coordinate);
			else if (str[coordinate.i][coordinate.j] == 'C')
				initialize("./assets/coin.xpm", &coordinate);
			else if (str[coordinate.i][coordinate.j] == 'P')
				initialize("./assets/sprit.xpm", &coordinate);
			coordinate.x += 50;
			coordinate.j++;
		}
		coordinate.y += 50;
	}
	mlx_loop(coordinate.mlx);
}
