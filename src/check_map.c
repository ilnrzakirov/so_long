/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:32:52 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:24 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_width_map(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = ft_strlen(map[0], '\0');
	while (map[i])
	{
		if (map[i + 1] == NULL)
		{
			if ((count - 1) == ft_strlen(map[i], '\0'))
				break ;
			else if (count == ft_strlen(map[i], '\0'))
				break ;
			else
				print_error("Invalid map");
		}
		else if (count != ft_strlen(map[i], '\0'))
			print_error("Invalid map");
		i++;
	}
	return (count);
}

int	get_higth_map(char **map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	get_treasure(char **map)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
	{
		check_error("Invalid map, there is no treasure");
		exit (0);
	}
	return (count);
}

void	get_object_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->pl_y = i;
				game->pl_x = j;
			}
			if (game->map[i][j] == 'E')
				game->home++;
			j++;
		}
		i++;
	}
	if (game->treasure < 1)
		print_error("nothing to collect");
	if (game->player != 1)
		print_error("Only one player can be present on the map");
}

void	check_objects(t_game *game)
{
	int	j;
	int	i;
	int	len;

	if (game->home < 1)
		print_error("No exit");
	i = 0;
	len = game->width_map - 2;
	while (game->map[i])
	{
		j = len;
		while (j >= 0)
		{
			if (i == 0 && game->map[i][j] != '1')
				print_error("Invalid map");
			if (i == (game->higth_map) - 1 && game->map[i][j] != '1')
				print_error("Invalid map");
			if ((j == 0 || j == len) && (game->map[i][j] != '1'))
				print_error("Invalid map");
			if (!(ft_strchr("10PCE", game->map[i][j])))
				print_error("Invalid map");
			j--;
		}
		i++;
	}
}
