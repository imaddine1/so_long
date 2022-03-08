/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:27:34 by iharile           #+#    #+#             */
/*   Updated: 2022/03/08 15:03:49 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(int fd, char *name_file)
{
	char	*str;

	str = ft_strchr(name_file, '.');
	if (!str)
		return (0);
	if (fd <= 0 || ft_strcmp(".ber", str) != 0)
		return (0);
	return (1);
}

int	valid_row(char **str)
{
	int	i;
	int	row;
	int	col;

	if (!str)
		return (0);
	i = 0;
	row = count_line(str) - 1;
	col = ft_strlen(*str);
	if (ft_strlen(str[0]) != ft_strlen(str[row]))
		return (0);
	/*while (str[0][i] && str[row][i])
	{
		if (str[0][i] != '1' || str[row][i] != '1')
			return (0);
		i++;
	}
	i = 0;*/
	while (i <= row)
	{
		printf ("%s\n", str[i]);
		i++;
	}
	/*while (str[i][0] && str[i][col - 1])
	{
		if (str[i][0] != '1' || str[i][col - 1] != '1')
			return (0);
		i++;
	}*/
	return (1);
}

void	valid_wall(int fd)
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
		all_text = ft_strjoin(line, all_text);
	}
	two_dimens = ft_split(all_text, '\n');
	if (!valid_row(two_dimens))
	{
		write (2, "Error: check the walls\n", 23);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int		fd;

	fd = open (av[1], O_RDONLY);
	if (ac <= 1 || ac > 2 || !check_file(fd, av[1]))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	valid_wall(fd);
	return (0);
}
