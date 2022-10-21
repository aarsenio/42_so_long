/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:52:49 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/14 17:45:53 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_str(char **map, int fd, int counter)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		map = map_str(map, fd, counter + 1);
	if (!map && counter != 0)
		map = malloc((counter + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	map[counter] = str;
	return (map);
}

void	map_cpy(t_window *data, int j, int i)
{
	data->tmp = malloc((data->h + 1) * sizeof(char *));
	if (!data->tmp)
		return ;
	while (data->map[j])
	{
		i = 0;
		data->tmp[j] = malloc((data->l + 2) * sizeof(char));
		while (data->map[j][i])
		{
			data->tmp[j][i] = data->map[j][i];
			i++;
		}
		data->tmp[j][i] = 0;
		j++;
	}
	data->tmp[j] = 0;
}
