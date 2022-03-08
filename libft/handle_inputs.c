/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:40:45 by iharile           #+#    #+#             */
/*   Updated: 2022/03/08 12:24:14 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	int				i;
	char			b;

	i = 0;
	str = (char *)s;
	b = (char)c;
	if (!s)
		return (0);
	while (str[i])
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	if (str[i] == b)
		return (&str[i]);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	p = malloc (sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (p == NULL)
		return (0);
	while (s1[i])
	{	
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
