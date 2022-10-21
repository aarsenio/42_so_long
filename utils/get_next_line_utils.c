/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:06:00 by aarsenio          #+#    #+#             */
/*   Updated: 2022/10/06 12:45:45 by aarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int	check_line_end(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (buffer[i] != '\n');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_line(char *line, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	temp = line;
	line = malloc(sizeof(char) * ft_strlen(buffer) + ft_strlen(line) + 1);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}	
	while (buffer[j])
	{
		line[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (temp)
		free(temp);
	return (line);
}

void	ft_clean_buff(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i])
	{
		if (j == -1 && buffer[i] == '\n')
			j = 0;
		else if (j >= 0)
			buffer[j++] = buffer[i];
		buffer[i++] = 0;
	}
}
