/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:55:44 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/08 13:17:21 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_struct(t_game *game)
{
	game->ptr_mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->width_map = 0;
	game->higth_map = 0;
	game->treasure = 0;
	game->player = 0;
	game->home = 0;
	game->pl_x = 0;
	game->pl_y = 0;
	game->count = 0;
	game->img_size = 65;
	game->tr_c = 0;
	game->tr.i = 0;
	game->ter_x = 0;
	game->ter_y = 0;
}

int	exit_game(void)
{
	exit (0);
	return (1);
}

void	start_game(t_game *game)
{
	int	win_h;
	int	win_w;

	game->ptr_mlx = mlx_init();
	win_h = (game->higth_map) * game->img_size;
	win_w = (game->width_map - 1) * game->img_size;
	game->mlx_win = mlx_new_window(game->ptr_mlx, win_w, win_h, "So_long");
	if (!(check_images(game)))
		print_error("error loading images");
	img_to_window(game, 0, 0, 0);
	mlx_loop_hook(game->ptr_mlx, animation, game);
	mlx_key_hook(game->mlx_win, layout, game);
	mlx_hook(game->mlx_win, 17, 0L, exit_game, 0);
	mlx_loop(game->ptr_mlx);
}

int	open_terrorist_object(t_game *game)
{
	int	w;
	int	h;

	game->img_ter.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/ttt.xpm", &w, &h);
	if (!(game->img_ter.img))
		return (0);
	return (1);
}

int	open_ground_object(t_game *game)
{
	int	w;
	int	h;

	game->img_gr.img = mlx_xpm_file_to_image(game->ptr_mlx,
			"./img/t.xpm", &w, &h);
	if (!(game->img_ter.img))
		return (0);
	return (1);
}
