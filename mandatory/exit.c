/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:53:39 by iharile           #+#    #+#             */
/*   Updated: 2022/03/22 17:18:08 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_exit(t_img *c, char ch)
{
	int	x;
	int	y;

	x = c->x_player / 50;
	y = c->y_player / 50;
	if (ch == 'w')
		if (c->str[y - 1][x] == 'E' && counter_constraint(c->str, 'C') == 0)
			exit(1);
	if (ch == 's')
		if (c->str[y + 1][x] == 'E' && counter_constraint(c->str, 'C') == 0)
			exit(1);
	if (ch == 'd')
		if (c->str[y][x + 1] == 'E' && counter_constraint(c->str, 'C') == 0)
			exit(1);
	if (ch == 'a')
		if (c->str[y][x - 1] == 'E' && counter_constraint(c->str, 'C') == 0)
			exit(1);
}
