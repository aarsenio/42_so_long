/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:40:43 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/25 10:36:24 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	chr_counter(t_window *data, int j, int i)
{
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				data->e_count++;
			if (data->map[j][i] == 'C')
				data->c_count++;
			if (data->map[j][i] == 'P')
				data->p_count++;
			if (data->map[j][i] != 'P' && data->map[j][i] != 'E' && \
			data->map[j][i] != 'C' && data->map[j][i] != '1' && \
			data->map[j][i] != '0' && data->map[j][i] != '2' && \
			data->map[j][i] != '\n')
				return (0);
			i++;
		}
		j++;
	}
	if (data->e_count != 1 || data->p_count != 1 || data->c_count < 1)
		return (0);
	return (1);
}

int	format_check(t_window *data, int i, int j)
{
	data->l = map_length(data->map);
	data->h = map_height(data->map);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'P')
			{
				data->x = i * 64;
				data->y = j * 64;
			}
			if (data->map[j][i] == 'E')
			{
				data->exit_x = i;
				data->exit_y = j;
			}
			i++;
		}
		if (i != data->l)
			return (0);
		j++;
	}
	return (1);
}

int	border_check(t_window *data, int i)
{
	while (i < data->l)
	{
		if (data->map[0][i] != '1' || data->map[data-> h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < data->h - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->l - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	name_check(char *str, int i)
{
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || \
	str[i - 3] != 'b' || str[i - 4] != '.')
		return (0);
	return (1);
}

void	path_checker(char **map, int x, int y)
{
	if (map[x + 1][y] && (map[x + 1][y] == 'C' || map[x + 1][y] == '0'))
	{
		map[x + 1][y] = 'P';
		path_checker(map, x + 1, y);
	}
	if (map[x - 1][y] && (map[x - 1][y] == 'C' || map[x - 1][y] == '0'))
	{
		map[x - 1][y] = 'P';
		path_checker(map, x - 1, y);
	}
	if (map[x][y + 1] && (map[x][y + 1] == 'C' || map[x][y + 1] == '0'))
	{
		map[x][y + 1] = 'P';
		path_checker(map, x, y + 1);
	}
	if (map[x][y - 1] && (map[x][y - 1] == 'C' || map[x][y - 1] == '0'))
	{
		map[x][y - 1] = 'P';
		path_checker(map, x, y - 1);
	}
}
