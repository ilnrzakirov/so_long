/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:47:42 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:26 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_sing(int n)
{
	int	i;

	if (n < 0)
	{
		i = 1;
	}
	else
		i = 0;
	return (i);
}

static int	get_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			i = 1;
		}
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_it_res(char *res, int len, int n)
{
	while (len >= 0)
	{
		*(res + len) = (n % 10) + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = get_sing(n) + get_len(n);
	if (n < 0)
	{
		i = 1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = -n;
	}
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	*(res + (len + 1)) = '\0';
	ft_it_res(res, len, n);
	if (i == 1)
		res[0] = '-';
	return (res);
}
