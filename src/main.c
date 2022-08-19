/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:47:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/26 15:58:16 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	keypress(int key, t_data *game)
{
	if (key == game->key_esc)
	{
		exit_game(game);
	}
	else if (((key == game->key_w) || (key == game->key_a)
			|| (key == game->key_s) || (key == game->key_d))
		&& game->end_game == 0)
	{
		printf("Player moves: %d Apples : %d\n", game->moves, game->n_collect);
		move_hero(key, game);
		game->moves++;
	}
	return (0);
}

void	play_game(t_data *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}

void	start_game(t_data *game)
{
	put_window(game);
	play_game(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	game;

	if (argc != 2 || open((const char *) argv[1], O_RDONLY) < 3)
		print_error("!!! Error !!! \nFile: main.c Line: 58");
	before_start_game(argc, argv[1], &game);
	start_game(&game);
	return (0);
}
