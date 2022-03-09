/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:46 by iharile           #+#    #+#             */
/*   Updated: 2022/03/09 12:25:52 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	void	*img;

	height = 10;
	width = 10;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./xpm/sprit_85_noBack.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
