/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:53:23 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:50:11 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if the map is surrounded by walls
int	map_is_surrounded(char *map, int columns, int lines)
{
	int	i;
	int	current_line;
	int	current_column;

	i = 0;
	current_line = 1;
	current_column = 1;
	while (map[i] != '\0')
	{
		if (i == 0 || current_column == 1 || current_column == columns
			|| current_line == 1 || current_line == lines)
		{
			if (map[i] != '1' && map[i] != '\n')
				return (0);
		}
		if (current_column == columns + 1)
		{
			current_column = 1;
			current_line++;
		}
		else
			current_column++;
		i++;
	}
	return (1);
}
