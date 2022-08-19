/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student@42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:58:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/05/10 12:39:42 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_window(t_data *game)
{
	game->mlx = mlx_init();
	window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	define_img(game);
	put_bg(game);
	draw_map(game);
}

void	window_size(t_data *game)
{
	int	i;

	game->map_w = (ft_strlen(game->map[0]) * 32);
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = (i * 32);
}

//mlx_destroy_display(game->mlx); bu neden çalışmıyo !?!?
//free(game->mlx); leak oluyor ??

int	exit_game(t_data *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_bg);
	mlx_destroy_image(game->mlx, game->img_hero);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	printf("bb");
	exit(EXIT_SUCCESS);
	return (0);
}

void	define_img(t_data *game)
{
	game->img_bg = mlx_xpm_file_to_image
		(game->mlx, "./img/bg/bg1.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "./img/exit.xpm", &game->img_w, &game->img_h);
	game->img_hero = mlx_xpm_file_to_image
		(game->mlx, "./img/hero.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "./img/wall.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "./img/collect.xpm", &game->img_w, &game->img_h);
	game->key_esc = 53;
	game->key_w = 13;
	game->key_a = 0;
	game->key_s = 1;
	game->key_d = 2;
	game->end_game = 0;
	game->moves = 1;
}

void	count_collect(t_data *game)
{
	int	i;
	int	j;
	int	a;

	j = 0;
	a = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'C')
				a++;
			i++;
		}
		j++;
	}
	if (a == 0)
		print_error("!!Error!!\nFile: utils_window.c Line:94");
	game->need = a;
}
