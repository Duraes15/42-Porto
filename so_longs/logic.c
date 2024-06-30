/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:17 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:45:56 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks if the determined "value" exists int the headquarter of integers
int	there_is_value(int **map, int value, int lines, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == value)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// will change the array based in the value. It will help the floodfil function
int	modifies_array(int ***map, int value, int lineColocar, int columnColocar)
{
	if ((*map)[lineColocar][columnColocar] < 0 &&
	(*map)[lineColocar][columnColocar] != -2)
	{
		(*map)[lineColocar][columnColocar] = value;
		return (1);
	}
	return (0);
}

// will call the modification of the array while there's a path 
int	puts_value(int ***map, int value, int lines, int columns)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < lines - 1)
	{
		j = 1;
		while (j < columns - 1)
		{
			if ((*map)[i][j] == value - 1)
			{
				flag += modifies_array(map, value, i - 1, j)
					+ modifies_array(map, value, i + 1, j);
				flag += modifies_array(map, value, i, j - 1)
					+ modifies_array(map, value, i, j + 1);
			}
			j++;
		}
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

// the algorithm to check if there's a valid path
int	flood_fill(int **map, int lines, int columns)
{
	int	i;
	int	value;
	int	flag;

	i = 1;
	value = 1;
	flag = 1;
	while (puts_value(&map, value, lines, columns))
	{
		value++;
	}
	if (there_is_value(map, -5, lines, columns)
		|| there_is_value(map, -3, lines, columns))
		return (0);
	return (1);
}
