/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:40:02 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:44 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image_animation(t_game *game, char sep, int x, int y)
{
	if (sep == 'T')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_ter.img, x, y);
	else if (sep == 'U')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_pl_up.img, x, y);
	else if (sep == 'R')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_pl_rh.img, x, y);
	else if (sep == 'L')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_pl_lh.img, x, y);
}

void	put_img(t_game *game, char sep, int x, int y)
{
	if (sep == '0')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_gr.img, x, y);
	else if (sep == '1')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_wl.img, x, y);
	else if (sep == 'E')
	{
		game->tr.x[game->tr.i] = x;
		game->tr.y[game->tr.i] = y;
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_hm.img, x, y);
	}
	else if (sep == 'P')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_pl.img, x, y);
	else if (sep == 'C')
		mlx_put_image_to_window(game->ptr_mlx, game->mlx_win,
			game->img_tr.img, x, y);
	else
		put_image_animation(game, sep, x, y);
}

void	img_to_window(t_game *game, int i, int j, int w)
{
	char	*s;

	s = ft_itoa(game->count);
	mlx_clear_window(game->ptr_mlx, game->mlx_win);
	w = game->img_size;
	while (i < game->width_map - 1)
	{
		j = 0;
		while (j < game->higth_map)
		{
			mlx_string_put(game->ptr_mlx, game->mlx_win, 5, 5, 0x00FF0000, s);
			put_img(game, game->map[j][i], (i * w), (j * w));
			j++;
		}
		i++;
	}
	free(s);
}
