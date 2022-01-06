/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:48:05 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:36 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_treasure_object(t_game *game)
{
	int	w;
	int	h;

	game->img_tr.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/mn1.xpm", &w, &h);
	if (!(game->img_tr.img))
		return (0);
	return (1);
}

int	open_home_object(t_game *game)
{
	int	w;
	int	h;

	game->img_hm.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/home.xpm", &w, &h);
	if (!(game->img_hm.img))
		return (0);
	return (1);
}

int	open_wall_object(t_game *game)
{
	int	w;
	int	h;

	game->img_wl.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/sten.xpm", &w, &h);
	if (!(game->img_wl.img))
		return (0);
	return (1);
}

int	open_player_object(t_game *game)
{
	int	w;
	int	h;

	game->img_pl.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/pl_dn.xpm", &w, &h);
	game->img_pl_up.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/pl_up.xpm", &w, &h);
	game->img_pl_rh.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/pl_rh.xpm", &w, &h);
	game->img_pl_lh.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/pl_lh.xpm", &w, &h);
	if (!(game->img_pl.img) || !(game->img_pl_up.img) || !(game->img_pl_rh.img))
		return (0);
	return (1);
}

int	check_images(t_game	*game)
{
	if (!(open_player_object(game)))
		return (0);
	if (!(open_treasure_object(game)))
		return (0);
	if (!(open_home_object(game)))
		return (0);
	if (!(open_wall_object(game)))
		return (0);
	if (!(open_terrorist_object(game)))
		return (0);
	if (!(open_ground_object(game)))
		return (0);
	return (1);
}
