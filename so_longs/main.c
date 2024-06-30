/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:22:28 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:41:54 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	mlx.map = NULL;
	if (fd == -1 || !is_ber(argv[1]) || argc != 2)
	{
		perror("Map reading error!");
		close (fd);
		return (0);
	}
	mlx.map = convert_map_to_char(fd, mlx.map);
	close (fd);
	mlx.headquarter = convert_map_to_headquarter(mlx.map,
			map_lines(mlx.map), map_is_rectangular(mlx.map));
	mlx.collectables = n_collectables(mlx.map);
	mlx.collecteds = 0;
	if (map_is_valid(mlx.map, mlx.headquarter))
		init_game(&mlx);
	else
		ft_printf("The map is not valid!\n");
	headquarter_free(&mlx);
	free (mlx.map);
}
