/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headquarter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:26 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 17:00:33 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// allocates the memory for the "headquarter"
int	**aloc_mem(int lines, int columns)
{
	int	i;
	int	**array;

	i = 0;
	array = malloc(sizeof(int *) * lines);
	while (i < lines)
	{
		array[i] = malloc(sizeof(int) * columns);
		i++;
	}
	return (array);
}

// chooses the integer to fulfil the "headquarter" based on the char given
int	choose_char(char c)
{
	if (c == 'C')
		return (-3);
	else if (c == 'E')
		return (0);
	else if (c == '1')
		return (-2);
	else if (c == '0')
		return (-1);
	else
		return (-5);
}

// converts the char *map to a headquarter of integers
int	**convert_map_to_headquarter(char *map, int lines, int columns)
{
	int	**map_in_headquarter;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	map_in_headquarter = aloc_mem(lines, columns);
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			map_in_headquarter[i][j] = choose_char(map[k]);
			j++;
			k++;
		}
		if (map[k] == '\n')
		{
			k++;
		}
		i++;
	}
	return (map_in_headquarter);
}

// free's the headquarter
void	headquarter_free(t_mlx_data *mlx)
{
	int	i;

	i = -1;
	while (++i < map_lines(mlx->map))
		free(mlx->headquarter[i]);
	free(mlx->headquarter);
}
