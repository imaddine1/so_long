/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:27:56 by iharile           #+#    #+#             */
/*   Updated: 2022/03/13 16:29:58 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct image
{
	char	**str;
	void	*mlx;
	void	*mlx_win;
	int		row;
	int		col;
	int		h;
	int		w;
	int		x;
	int		y;
	int		i;
	int		j;
	void	*img;
	int		x_player;
	int		y_player;
	int		nbr_coins;
	int		counter_coin;
	int		nbr_move;
}	t_img;
// libft stuff
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	ft_putnbr(long nb);
// other stuff
int		count_line(char **str);
char	**validate_map(int fd);
void	error(char *str);
void	so_long(char **str);
void	move_up(t_img *c);
void	move_down(t_img *c);
void	update(t_img *c, char *path);
int		move_isvalid(t_img *c, char **str, char ch);
void	move_right(t_img *c);
void	move_left(t_img *c);
int		counter_coin(char **str);
#endif