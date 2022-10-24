/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:13 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/24 17:08:47 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_window
{
	void	**images;
	void	*coin;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**tmp;
	int		h;
	int		l;
	int		e_count;
	int		c_count;
	int		p_count;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
}t_window;

char	**map_str(char **map, int fd, int counter);
void	map_cpy(t_window *data, int j, int i);
int		map_length(char **map);
int		map_height(char **map);
char	*ft_strdup(const char *s1);
void	*window_create(t_window *window);
int		chr_counter(t_window *data, int j, int i);
int		format_check(t_window *data, int i, int j);
int		border_check(t_window *data, int i);
int		name_check(char *str, int i);
void	path_checker(char **mapa, int x, int y);
void	map_render(t_window *window, int j, int i);
int		animation(void *param);
int		key(int keycode, void *param);
void	print_error(t_window *data, char *str, int error);
int		exit_game(t_window *data);

#endif