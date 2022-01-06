/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:30:42 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 15:25:39 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_img
{
	void	*img;
}	t_img;

typedef struct s_list
{
	int	x[250];
	int	y[250];
	int	i;
}	t_list;

typedef struct s_game
{
	void	*ptr_mlx;
	void	*mlx_win;
	char	**map;
	int		width_map;
	int		higth_map;
	int		treasure;
	int		player;
	int		pl_x;
	int		pl_y;
	int		home;
	int		img_size;
	int		count;
	t_img	img_pl;
	t_img	img_pl_up;
	t_img	img_pl_lh;
	t_img	img_pl_rh;
	t_img	img_tr;
	t_img	img_hm;
	t_img	img_wl;
	t_img	img_ter;
	t_img	img_gr;
	int		tr_c;
	t_list	tr;
	int		ter_x;
	int		ter_y;
}	t_game;

char	**init_map(int argc, char **argv);
int		check_error(char *text);
char	*ft_strnstr(const char *b, const char *l, size_t n);
void	init_game_struct(t_game *game);
int		count_line_in_file(char *file);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int s, int l, int flag);
char	*get_next_line(int fd);
int		check_static_var(char *rem, char **line);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strchr_st(const char *str, int sym);
int		ft_strlen(const char *str, char sym);
void	cut_line(char **line, char *rem, char *buf, int flag);
int		valid_map(t_game *game);
int		get_width_map(char **map);
int		get_higth_map(char **map);
int		get_treasure(char **map);
void	print_error(char *text);
void	get_object_map(t_game *game);
void	check_objects(t_game *game);
char	*ft_strchr(const char *str, int sym);
int		check_images(t_game *game);
void	start_game(t_game *game);
int		open_player_object(t_game *game);
int		open_terrorist_object(t_game *game);
void	img_to_window(t_game *game, int i, int j, int w);
int		open_ground_object(t_game *game);
int		layout(int key, t_game *game);
int		animation(t_game *game);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	get_ter_object(t_game *game);
void	game_over(void);
void	move_ter(t_game *game);
void	check_er(t_game *game);

#endif