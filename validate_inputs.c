/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:27:34 by iharile           #+#    #+#             */
/*   Updated: 2022/03/08 17:14:01 by iharile          ###   ########.fr       */
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

	fd = open (av[1], O_RDONLY);
	if (ac <= 1 || ac > 2 || !check_file(fd, av[1]))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	validate_map(fd);
	return (0);
}
