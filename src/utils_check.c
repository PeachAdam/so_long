/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:47:46 by yaysu             #+#    #+#             */
/*   Updated: 2022/05/10 14:20:28 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_first_line(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
			print_error("!!Error!!\nFile: utils_check.c Line: 24");
		i++;
	}
}

void	check_last_line(t_data *game)
{
	char	*s;
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != NULL)
			s = game->map[i];
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '1')
			print_error("!!Error!!\nFile: utils_check.c Line:46");
		i++;
	}
}

void	check_len_line(t_data *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(game->map[0]);
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i]) != j)
			print_error("!!Error!!\nFile: utils_check.c Line:61");
		i++;
	}
}

void	check_p_and_e(t_data *game)
{
	int	i;
	int	j;

	j = 0;
	game->exit_num = 0;
	game->player_num = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'P')
				game->player_num++;
			if (game->map[j][i] == 'E')
				game->exit_num++;
			i++;
		}
		j++;
	}
	if (game->exit_num != 1 || game->player_num != 1)
		print_error("!!Error!!\nFile: utils_check.c Line: 88");
}

void	before_start_game(int argc, char *argv, t_data *game)
{
	game->map = read_map(argv);
	count_collect(game);
	if (argc != 2 || ft_strnstr(argv, ".ber", ft_strlen(argv)) == NULL)
		print_error("!!Error!!\nFile: utils_check.c Line: 95");
	if (open(argv, O_RDONLY) < 3)
		print_error("!!Error!!\nFile: utils_check.c Line: 97");
	if (game->map[0] == NULL)
		print_error("!!Error!!\nFile: utils_check.c Line: 99");
	check_last_four(argv);
	check_first_line(game);
	check_last_line(game);
	check_len_line(game);
	check_body_map(game);
	check_other(game);
	printf("!!! Hoşgeldin !!!\nOyunun amacı pembe olan karakterin ");
	printf("aç olan beyaz arkadaşına tüm elmaları toplayıp götürmesidir");
	printf(" ama bunu diğer karakterlere değmeden yapmalıdır :) \n");
	printf("İyi eğlenceler\n");
}
