/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:53:01 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/17 17:39:41 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_error(t_window *data, char *str, int error)
{
	int	i;

	i = 0;
	if (error)
		write(1, "Error\n", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit_game(data);
}

static void	exit_game2(t_window *data)
{
	int	i;

	i = 0;
	if (data->images)
	{
		while (data->images[i])
			mlx_destroy_image(data->mlx, data->images[i++]);
		free(data->images);
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

int	exit_game(t_window *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i++]);
		}
		free(data->map);
	}
	i = 0;
	if (data->tmp)
	{
		while (data->tmp[i])
			free(data->tmp[i++]);
		free(data->tmp);
	}
	exit_game2(data);
	return (1);
}
