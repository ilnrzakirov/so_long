/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:59 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 15:31:47 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strnstr(const char *b, const char *l, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*l)
		return ((char *)b);
	while (b[i] && i < n)
	{
		j = 0;
		while (b[i + j] && l[j] && i + j < n && b[i + j] == l[j])
			j++;
		if (!l[j])
			return ((char *)(b + i));
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *str, int sym)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (char) sym)
			return (&p[i]);
		i++;
	}
	if (p[i] == (char) sym)
		return (&p[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		len;

	len = ft_strlen((char *)s, '\0');
	p = (char *)malloc(sizeof(*s) * (len + 1));
	if (p == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		p[len] = s[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

void	check_er(t_game *game)
{
	if (game->map[game->pl_y][game->pl_x] == 'T')
		game_over();
}
