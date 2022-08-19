/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student@42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:09:37 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/26 15:56:27 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_w(t_data *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == game->need)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->end_game = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		draw_map(game);
	}
}

void	move_s(t_data *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == game->need)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->end_game = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		draw_map(game);
	}
}

void	move_d(t_data *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect >= game->need)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->end_game = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		draw_map(game);
	}
}

void	move_a(t_data *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect >= game->need)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->end_game = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect += 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		draw_map(game);
	}
}

void	move_hero(int key, t_data *game)
{
	if (key == game->key_w)
	{
		game->y_player -= 1;
		move_w(game);
	}
	else if (key == game->key_s)
	{
		game->y_player += 1;
		move_s(game);
	}
	else if (key == game->key_d)
	{
		game->x_player += 1;
		move_d(game);
	}
	else if (key == game->key_a)
	{
		game->x_player -= 1;
		move_a(game);
	}
}
