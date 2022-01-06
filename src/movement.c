/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:04:17 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 15:24:54 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_up(t_game *game)
{
	if (game->treasure == 0)
	{
		if (game->map[game->pl_y - 1][game->pl_x] == 'E')
		{
			game->count++;
			printf("Steps: %d\n", game->count);
			exit (0);
		}
	}
	if (!(ft_strchr("1E", game->map[game->pl_y - 1][game->pl_x])))
	{
		if (game->map[game->pl_y - 1][game->pl_x] == 'C')
			game->treasure--;
		if (game->map[game->pl_y - 1][game->pl_x] == 'T')
			game_over();
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y--;
		game->map[game->pl_y][game->pl_x] = 'U';
		game->count++;
		printf("Steps: %d\n", game->count);
	}
}

void	player_down(t_game *game)
{
	if (game->treasure == 0)
	{
		if (game->map[game->pl_y + 1][game->pl_x] == 'E')
		{
			game->count++;
			printf("Steps: %d\n", game->count);
			exit (0);
		}
	}
	if (!(ft_strchr("1E", game->map[game->pl_y + 1][game->pl_x])))
	{
		if (game->map[game->pl_y + 1][game->pl_x] == 'C')
			game->treasure--;
		if (game->map[game->pl_y + 1][game->pl_x] == 'T')
			game_over();
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y++;
		game->map[game->pl_y][game->pl_x] = 'P';
		game->count++;
		printf("Steps: %d\n", game->count);
	}
}

void	player_left(t_game *game)
{
	if (game->treasure == 0)
	{
		if (game->map[game->pl_y][game->pl_x - 1] == 'E')
		{
			game->count++;
			printf("Steps: %d\n", game->count);
			exit (0);
		}
	}
	if (!(ft_strchr("1E", game->map[game->pl_y][game->pl_x - 1])))
	{
		if (game->map[game->pl_y][game->pl_x - 1] == 'C')
			game->treasure--;
		if (game->map[game->pl_y][game->pl_x - 1] == 'T')
			game_over();
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x--;
		game->map[game->pl_y][game->pl_x] = 'L';
		game->count++;
		printf("Steps: %d\n", game->count);
	}
}

void	player_rigth(t_game *game)
{
	if (game->treasure == 0)
	{
		if (game->map[game->pl_y][game->pl_x + 1] == 'E')
		{
			game->count++;
			printf("Steps: %d\n", game->count);
			exit (0);
		}
	}
	if (!(ft_strchr("1E", game->map[game->pl_y][game->pl_x + 1])))
	{
		if (game->map[game->pl_y][game->pl_x + 1] == 'C')
			game->treasure--;
		if (game->map[game->pl_y][game->pl_x + 1] == 'T')
			game_over();
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x++;
		game->map[game->pl_y][game->pl_x] = 'R';
		game->count++;
		printf("Steps: %d\n", game->count);
	}
}

int	layout(int key, t_game *game)
{
	if (key == 13)
	{
		player_up(game);
		move_ter(game);
	}
	if (key == 53)
		exit (0);
	if (key == 1)
	{
		player_down(game);
		move_ter(game);
	}
	if (key == 0)
	{
		player_left(game);
		move_ter(game);
	}
	if (key == 2)
	{
		player_rigth(game);
		move_ter(game);
	}
	check_er(game);
	img_to_window(game, 0, 0, 0);
	return (0);
}
