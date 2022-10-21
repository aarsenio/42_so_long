/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:58 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/14 17:08:57 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_itoa(int n)
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

int	coin_check(int c)
{
	if (c == 0)
		return (0);
	return (1);
}

static int	move_check(t_window *data, int keycode)
{
	int	x;
	int	y;

	x = (((keycode == 100) - (keycode == 97)) * 64) + data->x;
	y = (((keycode == 115) - (keycode == 119)) * 64) + data->y;
	if (data->map[y / 64][x / 64] == '1')
		return (0);
	if (data->map[y / 64][x / 64] == '2')
		print_error(data, "You Lose!", 0);
	if (data->map[y / 64][x / 64] == 'E')
	{
		if (!coin_check(data->c_count))
			print_error(data, "You Win!", 0);
		return (0);
	}
	if (data->map[y / 64][x / 64] == 'C')
	{
		data->c_count--;
		data->map[y / 64][x / 64] = '0';
		if (!coin_check(data->c_count))
			mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->images[11], data->exit_x, \
			data->exit_y);
	}
	return (1);
}

void	print_move(int keycode, t_window *data)
{
	data->x += (((keycode == 100) - (keycode == 97)) * 64);
	data->y += (((keycode == 115) - (keycode == 119)) * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->images[(keycode == 97) * 1 + (keycode == 119) * 2 + \
	(keycode == 115) * 3], data->x, data->y);
	if (keycode == 100)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[5], \
		data->x - 64, data->y);
	if (keycode == 97)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[5], \
		data->x + 64, data->y);
	if (keycode == 119)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[5], \
		data->x, data->y + 64);
	if (keycode == 115)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[5], \
		data->x, data->y - 64);
}

int	key(int keycode, void *param)
{
	t_window	*data;
	static int	count_steps;
	char		*str;

	data = param;
	if (keycode == 65307)
		print_error(data, "Quit Game", 0);
	if (!(keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119))
		return (0);
	if (move_check(data, keycode))
	{		
		count_steps++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[4], \
		0, 0);
		str = ft_itoa(count_steps);
		mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, str);
		free(str);
		print_move(keycode, data);
	}
	return (1);
}
