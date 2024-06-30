/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:59 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:47:34 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks if the map is valid
int	map_is_valid(char *map, int **headquarter_map)
{
	int	columns;
	int	lines;

	columns = map_is_rectangular(map);
	lines = map_lines(map);
	if (columns <= 2 || lines <= 2 || !map_only_valid_chars(map)
		|| !map_is_surrounded(map, columns, lines) || !elements_ok(map))
		return (0);
	return (flood_fill(headquarter_map, lines, columns));
}
// checks if the map is .ber

int	is_ber(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] == 'r'
		&& filename[len - 2] == 'e'
		&& filename[len - 3] == 'b'
		&& filename[len - 4] == '.')
		return (1);
	return (0);
}
