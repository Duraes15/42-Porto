/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:57:52 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:52:51 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// cleans everything needed in the mlx struct
// and closes the window (ESC or cross click)
int	complete_deletion(t_mlx_data *mlx)
{
	int	i;

	i = -1;
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->headquarter)
	{
		while (++i < map_lines(mlx->map))
			free(mlx->headquarter[i]);
		free(mlx->headquarter);
	}
	free (mlx->map);
	exit(0);
	return (0);
}

//  decides what is needed to be done when a key is presses
int	handle_key_releasing(int key_code, t_mlx_data *window)
{
	if (key_code == 65307 || key_code == -16777896)
	{
		complete_deletion(window);
	}
	else if (key_code == 'd' || key_code == 'D')
		go_right(window);
	else if (key_code == 'w' || key_code == 'W')
		go_up(window);
	else if (key_code == 'a' || key_code == 'A')
		go_left(window);
	else if (key_code == 's' || key_code == 'S')
		go_down(window);
	return (0);
}

//  decides the texture based on the headquarter of the mlx struct
void	*decide_texture(t_mlx_data *mlx, int i, int j)
{
	if (mlx->headquarter[i][j] == -2)
		return (mlx_xpm_file_to_image(mlx->mlx,
				"textures/wall.xpm", &(mlx->width), &(mlx->height)));
	else if (mlx->headquarter[i][j] == -1)
		return (mlx_xpm_file_to_image(mlx->mlx,
				"textures/empty.xpm", &(mlx->width), &(mlx->height)));
	else if (mlx->headquarter[i][j] == -3)
		return (mlx_xpm_file_to_image(mlx->mlx,
				"textures/collectable.xmp", &(mlx->width), &(mlx->height)));
	else if (mlx->headquarter[i][j] == -5)
		return (mlx_xpm_file_to_image(mlx->mlx,
				"textures/player.xpm", &(mlx->width), &(mlx->height)));
	else
		return (mlx_xpm_file_to_image(mlx->mlx,
				"textures/exit.xpm", &(mlx->width), &(mlx->height)));
}

// will renderize the image based on the headquarter
void	render(t_mlx_data *mlx, int lines, int columns)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			mlx->img = decide_texture(mlx, i, j);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
			mlx_destroy_image(mlx->mlx, mlx->img);
			x += 32;
			if (x == columns * 32)
				x = 0;
			j++;
		}
		y += 32;
		i++;
	}
}

// initializes the game when the map is valid
void	init_game(t_mlx_data *mlx)
{
	mlx->moves = 0;
	headquarter_free(mlx);
	mlx->headquarter = convert_map_to_headquarter(mlx->map,
			map_lines(mlx->map), map_is_rectangular(mlx->map));
	mlx->mlx = mlx_init();
	mlx->lines = map_lines(mlx->map);
	mlx->columns = map_is_rectangular(mlx->map);
	mlx->win = mlx_new_window(mlx->mlx,
			(mlx->columns * 32), (mlx->lines * 32), "so_long");
	render(mlx, mlx->lines, mlx->columns);
	mlx_hook(mlx->win, 2, 1L << 0, handle_key_releasing, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, complete_deletion, mlx);
	mlx_loop(mlx->mlx);
}
