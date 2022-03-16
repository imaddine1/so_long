/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:53:52 by iharile           #+#    #+#             */
/*   Updated: 2022/03/16 11:01:56 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_element(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	free_2dimension(char **double_table)
{
	int	i;
	int	row;

	i = 0;
	row = count_line(double_table);
	while (i < row)
	{
		free(double_table[i]);
		i++;
	}
	free(double_table);
}

int	valid_row(char **str)
{
	int	i;
	int	row;
	int	col;

	if (!str)
		return (0);
	i = 0;
	row = count_line(str);
	col = ft_strlen(*str);
	if (row * col != count_element(str))
		return (0);
	while (str[0][i] && str[row - 1][i])
	{
		if (str[0][i] != '1' || str[row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i <= row - 1)
	{
		if (str[i][0] != '1' || str[i][col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_constraints(char *str)
{
	int	i;
	int	p;
	int	c;
	int	e;
	int	s;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == 'P')
			p = 1;
		else if (str[i] == 'C')
			c = 1;
		else if (str[i] == 'E')
			e = 1;
		else if (str[i] == '0')
			s = 1;
		i++;
	}
	if (p == 1 && c == 1 && e == 1 && s == 1)
		return (1);
	return (0);
}

char	**validate_map(int fd)
{
	char	*line;
	int		i;
	char	*all_text;
	char	**two_dimens;

	line = malloc(sizeof(char) * 2);
	i = 1;
	while (i)
	{
		i = read(fd, line, 1);
		if (i <= 0)
			break ;
		line[1] = 0;
		all_text = ft_strjoin(all_text, line);
	}
	free(line);
	two_dimens = ft_split(all_text, '\n');
	if (!valid_row(two_dimens) || !check_constraints(all_text))
		error("Error: The map is incorrect\n");
	free(all_text);
	return (two_dimens);
}
