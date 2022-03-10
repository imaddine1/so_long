/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:35 by iharile           #+#    #+#             */
/*   Updated: 2022/03/10 12:23:14 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_coordinate(t_img *coor, char **s)
{
	coor->row = count_line(s);
	coor->col = ft_strlen(*s);
	coor->x = 0;
	coor->y = 0;
}

void	initialize(char *path, t_img *coordinate)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, , , "So_long!");
	img = mlx_xpm_file_to_image(mlx, path, &h, &w);
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
}

void	so_long(int fd, char **str)
{
	int		i;
	int		j;
	t_img	coordinate;

	initialize_image(&coordinate, str);
	i = 0;
	while (str[i][j])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1')
			{
				
			}
			j++;
		}
		i++;
	}
}
