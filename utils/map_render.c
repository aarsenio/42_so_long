/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:10:22 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/24 17:44:00 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	animation_render(t_window *data)
{
	int			i;
	int			j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, \
				data->mlx_win, data->coin, i * 64, j * 64);
			if (data->map[j][i] == '2')
				mlx_put_image_to_window(data->mlx, \
				data->mlx_win, data->enemy, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

int	animation(void *param)
{
	t_window	*data;
	static int	index = 6;
	static int	index_e = 12;
	static int	count;

	data = param;
	if (count >= 15000)
	{
		if (index == 10)
			index = 6;
		if (index_e == 15)
			index_e = 12;
		data->coin = data->images[index];
		data->enemy = data->images[index_e];
		index++;
		index_e++;
		animation_render(data);
		count = 0;
	}
	else
		count++;
	return (0);
}

static void	image_load(t_window *window, int x, int y, int i)
{
	char	*str;

	str = ft_strdup("images/00.xpm");
	if (!str)
		return ;
	window->images = malloc(16 * sizeof(void *));
	if (!window->images)
		return ;
	while (i < 15)
	{
		window->images[i] = mlx_xpm_file_to_image(window->mlx, str, &x, &y);
		if (i == 9)
		{
			str[8] = 47;
			str[7] += 1;
		}
		str[8] += 1;
		i++;
	}
	window->images[15] = NULL;
	free(str);
}

static void	map_printer(t_window *window, int j, int i)
{
	if (window->map[j][i] == '1')
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[4], i * 64, j * 64);
	if (window->map[j][i] == '2')
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[12], i * 64, j * 64);
	if (window->map[j][i] == '0')
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[5], i * 64, j * 64);
	if (window->map[j][i] == 'E')
	{
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[10], i * 64, j * 64);
	}
	if (window->map[j][i] == 'C')
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[6], i * 64, j * 64);
	if (window->map[j][i] == 'P')
	{
		mlx_put_image_to_window(window->mlx, \
		window->mlx_win, window->images[3], i * 64, j * 64);
	}
}

void	map_render(t_window *window, int j, int i)
{
	image_load(window, 64, 64, 0);
	while (window->map[j])
	{
		i = 0;
		while (window->map[j][i])
		{
			map_printer(window, j, i);
			i++;
		}
		j++;
	}
}
