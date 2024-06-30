/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:59:28 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:41:55 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// changes the p_x and p_y of the struct mlx in order to 
// find the player coordenates
void	player_position(t_mlx_data **mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*mlx)->lines)
	{
		j = 0;
		while (j < (*mlx)->columns)
		{
			if ((*mlx)->headquarter[i][j] == -5)
			{
				(*mlx)->p_x = j + 1;
				(*mlx)->p_y = i + 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

// what is done when you try to go right
void	go_right(t_mlx_data *mlx)
{
	player_position(&mlx);
	if (mlx->headquarter[mlx->p_y - 1][mlx->p_x] == -1 ||
	mlx->headquarter[mlx->p_y - 1][mlx->p_x] == -3)
	{
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] != 0)
			mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x] == -3)
			mlx->collecteds++;
		mlx->headquarter[mlx->p_y - 1][mlx->p_x] = -5;
		(mlx->p_x)++;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
	else if (mlx->headquarter[mlx->p_y - 1][mlx->p_x] == 0)
	{
		if (mlx->collecteds == mlx->collectables)
		{
			ft_printf("Move %d\n", ++(mlx->moves));
			complete_deletion(mlx);
		}
		mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		(mlx->p_x)++;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
}

// what is done when you try to go left
void	go_left(t_mlx_data *mlx)
{
	player_position(&mlx);
	if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 2] == -1 ||
	mlx->headquarter[mlx->p_y - 1][mlx->p_x - 2] == -3)
	{
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] != 0)
			mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 2] == -3)
			mlx->collecteds++;
		mlx->headquarter[mlx->p_y - 1][mlx->p_x - 2] = -5;
		(mlx->p_x)--;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
	else if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 2] == 0)
	{
		if (mlx->collecteds == mlx->collectables)
		{
			ft_printf("Move %d\n", ++(mlx->moves));
			complete_deletion(mlx);
		}
		mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		(mlx->p_x)--;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
}

// what is done when you try to go up
void	go_up(t_mlx_data *mlx)
{
	player_position(&mlx);
	if (mlx->headquarter[mlx->p_y - 2][mlx->p_x - 1] == -1 ||
	mlx->headquarter[mlx->p_y - 2][mlx->p_x - 1] == -3)
	{
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] != 0)
			mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		if (mlx->headquarter[mlx->p_y - 2][mlx->p_x - 1] == -3)
			mlx->collecteds++;
		mlx->headquarter[mlx->p_y - 2][mlx->p_x - 1] = -5;
		(mlx->p_y)--;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
	else if (mlx->headquarter[mlx->p_y - 2][mlx->p_x - 1] == 0)
	{
		if (mlx->collecteds == mlx->collectables)
		{
			ft_printf("Move %d\n", ++(mlx->moves));
			complete_deletion(mlx);
		}
		mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		(mlx->p_y)--;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
}

// what is done when you try to go down
void	go_down(t_mlx_data *mlx)
{
	player_position(&mlx);
	if (mlx->headquarter[mlx->p_y][mlx->p_x - 1] == -1 ||
	mlx->headquarter[mlx->p_y][mlx->p_x - 1] == -3)
	{
		if (mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] != 0)
			mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		if (mlx->headquarter[mlx->p_y][mlx->p_x - 1] == -3)
			mlx->collecteds++;
		mlx->headquarter[mlx->p_y][mlx->p_x - 1] = -5;
		(mlx->p_y)++;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
	else if (mlx->headquarter[mlx->p_y][mlx->p_x - 1] == 0)
	{
		if (mlx->collecteds == mlx->collectables)
		{
			ft_printf("Move %d\n", ++(mlx->moves));
			complete_deletion(mlx);
		}
		mlx->headquarter[mlx->p_y - 1][mlx->p_x - 1] = -1;
		(mlx->p_y)++;
		ft_printf("Move %d\n", ++(mlx->moves));
		render(mlx, mlx->lines, mlx->columns);
	}
}
