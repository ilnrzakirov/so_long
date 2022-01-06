/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:12:51 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 13:09:08 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_ter_object(t_game *game)
{
	if (game->width_map > 6)
	{
		if (game->higth_map > 3)
		{
			if (!(ft_strchr("1ECP", game->map[game->higth_map - 2]
						[game->width_map - 3])))
			{
				game->map[game->higth_map - 2][game->width_map - 3] = 'T';
				game->ter_x = game->width_map - 3;
				game->ter_y = game->higth_map - 2;
			}
		}
	}
}

int	valid_map(t_game *game)
{
	game->width_map = get_width_map(game->map);
	game->higth_map = get_higth_map(game->map);
	game->treasure = get_treasure(game->map);
	get_object_map(game);
	check_objects(game);
	get_ter_object(game);
	return (1);
}

char	**init_matrix(char *file)
{
	int		count_line;
	char	**map;
	char	*line;
	int		i;
	int		fd;

	count_line = count_line_in_file(file);
	map = malloc(sizeof(char **) * (count_line + 1));
	i = 1;
	if (!map)
		exit (0);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map[0] = line;
	while (map[i - 1])
		map[i++] = get_next_line(fd);
	close(fd);
	return (map);
}

int	valid_map_file(int argc, char *argv)
{
	int	len;

	if (argc == 1)
		return (check_error("No map file"));
	else if (argc == 2)
	{
		len = ft_strlen(argv, '\0');
		if (!(ft_strnstr(&argv[len - 4], ".ber", 4)))
			return (check_error(".ber file not found"));
		return (1);
	}
	else
		return (check_error("You can't use multiple maps"));
}

char	**init_map(int argc, char **argv)
{
	if (!(valid_map_file(argc, argv[1])))
		return (NULL);
	return (init_matrix(argv[1]));
}
