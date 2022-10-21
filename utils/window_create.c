/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:02:57 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/21 16:33:46 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_length(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
		i++;
	return (i);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(14 * sizeof(char));
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}

void	*window_create(t_window *window)
{
	return (mlx_new_window(window->mlx, (window->l) * 64, \
		window->h * 64, "so_long"));
}
