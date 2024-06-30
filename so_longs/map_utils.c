/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:52:18 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/20 13:32:46 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// return the length of the line
int	line_len(char *str, int index)
{
	int	j;

	j = 0;
	while (str[index] != '\0' && str[index] != '\n')
	{
		index++;
		j++;
	}
	return (j);
}

// return the number of columns that exist if 
// the map is rectangular. Otherwise it returns 0
int	map_is_rectangular(char *map)
{
	int	i;
	int	line_len_v;
	int	j;

	i = 0;
	j = 0;
	line_len_v = 0;
	while (map[i] != '\0')
	{
		j = line_len(map, i);
		if (j != line_len_v)
		{
			if (line_len_v != 0)
				return (0);
			else
				line_len_v = j;
		}
		if (map[i + j] == '\0')
			i = i + j;
		else
			i = i + j + 1;
	}
	return (line_len_v);
}

// return the number of lines of the map
int	map_lines(char *map)
{
	int	i;
	int	new_lines;

	i = 0;
	new_lines = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			new_lines++;
		i++;
	}
	return (new_lines);
}

// check if the map only has valid chars
int	map_only_valid_chars(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1'
			&& map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P'
			&& map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// check if the number of each element is right
int	elements_ok(char *map)
{
	int	i;
	int	n_exits;
	int	n_starting_points;
	int	n_collectibles;

	i = 0;
	n_exits = 0;
	n_starting_points = 0;
	n_collectibles = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			n_collectibles++;
		else if (map[i] == 'E')
			n_exits++;
		else if (map[i] == 'P')
			n_starting_points++;
		i++;
	}
	if (n_collectibles >= 1 && n_exits == 1 && n_starting_points == 1)
		return (1);
	return (0);
}
