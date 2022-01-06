/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:38:35 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:31 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = (void *)malloc(n * size);
	if (!p)
		return (NULL);
	while (i < n)
	{
		*(char *)(p + i) = '\0';
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = ft_calloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1), 1);
	if (s == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	free(s1);
	return (s);
}

int	ft_strlen(const char *str, char sym)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != sym && str[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char *str, int s, int l, int flag)
{
	int		i;
	int		k;
	char	*res;

	if (ft_strlen(str, '\0') < (s + l))
		l = ft_strlen(str, '\0') - s;
	res = malloc((sizeof(char) * (l + 1)));
	k = 0;
	if (s >= 0 && (ft_strlen((char *)str, '\0') > s))
	{
		i = s;
		while (str[i] && k < l)
			res[k++] = str[i++];
		res[k] = '\0';
		if (flag == 1)
			free(str);
		return (res);
	}
	res[k] = '\0';
	if (flag == 1)
		free(str);
	return (res);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
