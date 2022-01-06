/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:36:28 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:59:05 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game, int argc, char **argv)
{
	init_game_struct(game);
	game->map = init_map(argc, argv);
	if (game->map == NULL)
		return (0);
	if (!(valid_map(game)))
		return (check_error("Invalid map"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (!(init_game(&game, argc, argv)))
		return (0);
	start_game(&game);
	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	return (0);
}
