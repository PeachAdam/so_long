/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:01:19 by yaysu             #+#    #+#             */
/*   Updated: 2022/05/10 14:08:48 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_bg;
	void	*img_hero;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	int		exit_num;
	int		player_num;
	int		map_h;
	int		map_w;
	int		img_h;
	int		img_w;
	int		x_player;
	int		y_player;
	int		n_collect;
	int		key_esc;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		end_game;
	int		moves;
	int		need;
}				t_data;

int			draw_map(t_data *game);
void		print_error(char *message);
void		before_start_game(int argc, char *argv, t_data *game);
char		**read_map(char *path);
void		free_map(char **map);
void		check_first_line(t_data *game);
void		check_last_line(t_data *game);
void		check_len_line(t_data *game);
void		check_body_map(t_data *game);
void		check_body_wall(t_data *game);
void		check_p_and_e(t_data *game);
void		start_game(t_data *game);
void		put_window(t_data *game);
void		put_bg(t_data *game);
void		window_size(t_data *game);
void		define_img(t_data *game);
void		img_draw(t_data *game, void *image, int x, int y);
int			exit_game(t_data *game);
void		move_w(t_data *game);
void		move_s(t_data *game);
void		move_a(t_data *game);
void		move_d(t_data *game);
void		move_hero(int key, t_data *game);
void		count_collect(t_data *game);
int			keypress(int key, t_data *game);
void		play_game(t_data *game);
void		player_update_image(char key, t_data *game);
void		check_other(t_data *game);
void		check_last_four(char *argv);

#endif
