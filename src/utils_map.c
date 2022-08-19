/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:47:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/04/20 12:10:20 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != (void *)0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_body_map(t_data *game)
{
	check_p_and_e(game);
	check_body_wall(game);
}

void	check_body_wall(t_data *game)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(game->map[j]);
	while (game->map[j] != NULL)
	{
		if (game->map[j][0] != '1')
			print_error("!!Error!!\nFile: utils_map.c Line: 72");
		if (game->map[j][i - 1] != '1')
			print_error("!!Error!!\nFile: utils_map.c Line: 74");
		j++;
	}
}

void	player_update_image(char key, t_data *game)
{
	mlx_destroy_image(game->mlx, game->img_hero);
	if (key == 'd')
		game->img_hero = mlx_xpm_file_to_image
			(game->mlx, "./img/hero.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_hero = mlx_xpm_file_to_image
			(game->mlx, "./img/hero_left.xpm", &game->img_w, &game->img_h);
}
