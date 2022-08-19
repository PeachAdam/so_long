/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:47:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/21 12:32:57 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_draw(t_data *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

static void	draw_player(t_data *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

static void	draw_exit(t_data *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "./img/exit.xpm", &game->img_w, &game->img_h);
	}
	img_draw(game, game->img_exit, x, y);
}

int	draw_map(t_data *game)
{
	int	i;
	int	j;

	j = 0;
	put_bg(game);
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] == '1')
				img_draw(game, game->img_wall, i, j);
			else if (game->map[j][i] == 'P')
				draw_player(game, game->img_hero, i, j);
			else if (game->map[j][i] == 'C')
				img_draw(game, game->img_collect, i, j);
			else if (game->map[j][i] == 'E')
				draw_exit(game, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

void	put_bg(t_data *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			img_draw(game, game->img_bg, i, j);
			i++;
		}
		j++;
	}
}
