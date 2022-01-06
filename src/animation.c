/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:51:57 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:18 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_game *game)
{
	static int	u;
	int			w;
	int			h;

	if (u % 12 == 0)
	{
		game->img_tr.img = mlx_xpm_file_to_image(game->ptr_mlx,
				"./img/mn2.xpm", &w, &h);
	}
	if (u % 24 == 0)
	{
		game->img_tr.img = mlx_xpm_file_to_image(game->ptr_mlx,
				"./img/mn3.xpm", &w, &h);
	}
	if (u % 36 == 0)
	{
		game->img_tr.img = mlx_xpm_file_to_image(game->ptr_mlx,
				"./img/mn1.xpm", &w, &h);
	}
	u++;
	img_to_window(game, 0, 0, 0);
	return (0);
}

void	move_ter(t_game *game)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x - 1])))
	{
		game->map[game->ter_y][game->ter_x - 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x--;
	}
	else if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x + 1])))
	{
		game->map[game->ter_y][game->ter_x + 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x++;
	}
	else if (!(ft_strchr("1EC", game->map[game->ter_y + 1][game->ter_x])))
	{
		game->map[game->ter_y + 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y++;
	}
	else if (!(ft_strchr("1EC", game->map[game->ter_y - 1][game->ter_x])))
	{
		game->map[game->ter_y - 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y--;
	}
}
