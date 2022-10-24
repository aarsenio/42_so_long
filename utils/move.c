/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:58 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/24 17:05:35 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		i;

	i = 0;
	nbr = n;
	if (n == 0)
		str = "0";
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	nbr = n;
	str[i--] = '\0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

static int	coin_check(int c)
{
	if (c == 0)
		return (0);
	return (1);
}

static int	move_check(int x, int y, t_window *data)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == '2')
		print_error(data, "You Lose!", 0);
	if (data->map[y][x] == 'E')
	{
		if (!coin_check(data->c_count))
			print_error(data, "You Win!", 0);
		return (0);
	}
	if (data->map[y][x] == 'C')
	{
		data->c_count--;
		data->map[y][x] = '0';
		if (!coin_check(data->c_count))
			mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->images[11], data->exit_x, \
			data->exit_y);
	}
	return (1);
}

static void	print_move(int x, int y, int keycode, t_window *data)
{
	static int	count_steps;
	char		*str;
	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[5], \
		data->x, data->y);
	data->x += (x * 64);
	data->y += (y * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->images[(keycode == 97) * 1 + (keycode == 119) * 2 + \
	(keycode == 115) * 3], data->x, data->y);
	count_steps++;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[4], \
	0, 0);
	str = ft_itoa(count_steps);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, str);
	free(str);
}

int	key(int keycode, void *param)
{
	t_window	*data;
	int			x;
	int			y;

	data = param;
	if (keycode == 65307)
		print_error(data, "Quit Game", 0);
	if (!(keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119))
		return (0);
	x = ((keycode == 100) - (keycode == 97));
	y = ((keycode == 115) - (keycode == 119));
	if (move_check((data->x / 64) + x, (data->y / 64) + y, data))
		print_move(x, y, keycode, data);
	return (1);
}
