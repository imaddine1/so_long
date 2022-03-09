/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:27:56 by iharile           #+#    #+#             */
/*   Updated: 2022/03/09 09:06:06 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

// libft stuff
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
// other stuff
int		count_line(char **str);
void	validate_map(int fd);
void	error(char *str);
#endif