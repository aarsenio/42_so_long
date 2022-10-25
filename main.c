/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:52:54 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/25 13:02:40 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	validater(t_window *data, int j, int i)
{
	if (!chr_counter(data, 0, 0))
		print_error(data, "Invalid map", 1);
	if (!format_check(data, 0, 0))
		print_error(data, "Map is not a Rectangle", 1);
	if (!border_check(data, 0))
		print_error(data, "Map is not surrounded by walls", 1);
	map_cpy(data, 0, 0);
	path_checker(data->tmp, data->y / 64, data->x / 64);
	while (data->tmp[j])
	{
		i = 0;
		while (data->tmp[j][i])
		{
			if (data->tmp[j][i] == 'C')
				print_error(data, "Path is not valid", 1);
			i++;
		}
		j++;
	}
	if (!(data->tmp[data->exit_y + 1][data->exit_x] == 'P' || data->tmp[\
	data->exit_y - 1][data->exit_x] == 'P' || data->tmp[data->exit_y][\
	data->exit_x + 1] == 'P' || data->tmp[data->exit_y] \
	[data->exit_x - 1] == 'P'))
		print_error(data, "Path is not valid", 1);
}

int	main(int argc, char **argv)
{
	int				fd;
	static t_window	window;

	if (argc != 2)
		print_error(&window, "Wrong number of arguments", 1);
	if (!name_check(argv[1], 0))
		print_error(&window, "Invalid map name", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(&window, "Invalid Map File", 1);
	window.map = map_str(NULL, fd, 0);
	close(fd);
	if (!window.map)
		print_error(&window, "Empty map", 1);
	validater(&window, 0, 0);
	window.exit_x *= 64;
	window.exit_y *= 64;
	window.mlx = mlx_init();
	window.mlx_win = window_create(&window);
	map_render(&window, 0, 0);
	mlx_hook(window.mlx_win, 02, (1L << 0), key, &window);
	mlx_hook(window.mlx_win, 17, (1L << 2), exit_game, &window);
	mlx_loop_hook(window.mlx, animation, &window);
	mlx_loop(window.mlx);
}
