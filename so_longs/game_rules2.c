/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:00:38 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:36:33 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// counts the number of collectable that exists in the map
int	n_collectables(char *map)
{
	int	i;
	int	collectables;

	i = 0;
	collectables = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			collectables++;
		i++;
	}
	return (collectables);
}
