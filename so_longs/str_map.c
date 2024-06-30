/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:51:05 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/20 12:51:56 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// it will say the len of the whole string including '\0'
int	ft_strlen_including_null(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

// will add the read by the function read to the string "map"
char	*add_char_to_string(char *map, char c, int strlen_including_null)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char) * (strlen_including_null + 1));
	while (map[i] != '\0')
	{
		copy[i] = map[i];
		i++;
	}
	copy[i++] = c;
	copy[i] = '\0';
	free(map);
	map = malloc(ft_strlen_including_null(copy));
	i = 0;
	while (copy[i] != '\0')
	{
		map[i] = copy[i];
		i++;
	}
	map[i] = '\0';
	free(copy);
	return (map);
}

// will convert the map into a string
char	*convert_map_to_char(int fd, char *map)
{
	char	buffer[1];

	map = malloc(sizeof(char));
	map[0] = '\0';
	while (read(fd, buffer, 1))
	{
		map = add_char_to_string(map, buffer[0], ft_strlen_including_null(map));
	}
	return (map);
}
