/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student@42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:16:56 by yaysu             #+#    #+#             */
/*   Updated: 2022/05/10 14:39:52 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_other(t_data *game)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			c = game->map[j][i];
			if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C')
				i++;
			else
				print_error("!!Error!!\nFile: utils_other.c Line: 29");
		}
		j++;
	}
}

void	check_last_four(char *argv)
{
	int		i;

	i = ft_strlen(argv);
	if ((argv[i - 4]) != '.')
		print_error("!!Error!!\nFile: utils_other.c Line:43");
	if ((argv[i - 3]) != 'b')
		print_error("!!Error!!\nFile: utils_other.c Line:45");
	if ((argv[i - 2]) != 'e')
		print_error("!!Error!!\nFile: utils_other.c Line:47");
	if ((argv[i - 1]) != 'r')
		print_error("!!Error!!\nFile: utils_other.c Line:49");
}
