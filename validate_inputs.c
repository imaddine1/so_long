/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:27:34 by iharile           #+#    #+#             */
/*   Updated: 2022/03/08 12:28:04 by iharile          ###   ########.fr       */
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


int	main(int ac, char **av)
{
	int		fd;
	char	**text_file;
	char	*line;
	char	*all_text;
	int		i;

	fd = open (av[1], O_RDONLY);
	if (ac <= 1 || ac > 2 || !check_file(fd, av[1]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	line = malloc (sizeof(char) * 2);
	i = 1;
	all_text = "\0";
	while (i)
	{
		i = read (fd, line, 1);
		if (i <= 0)
			break ;
		line[1] = 0;
		all_text = ft_strjoin(line, all_text);
	}
	text_file = ft_split(all_text, '\n');
	return (0);
}
