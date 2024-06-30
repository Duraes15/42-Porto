/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:04 by joao-oli          #+#    #+#             */
/*   Updated: 2024/06/26 16:52:53 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft_printf/libft.h"
#include "minilibx-linux/mlx.h"

typedef struct position
{
	int		x;
	int		y;
}	t_ponto;

typedef struct dados
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*map;
	int		**headquarter;
	int		height;
	int		width;
	int		lines;
	int		columns;
	int		p_x;
	int		p_y;
	int		collecteds;
	int		collectables;
	int		moves;
}	t_mlx_data;

int		ft_strlen_including_null(char *str);
char	*add_char_to_string(char *map, char c, int strlen_including_null);
char	*convert_map_to_char(int fd, char *map);
int		line_len(char *str, int index);
int		map_is_rectangular(char *map);
int		map_lines(char *map);
int		map_only_valid_chars(char *map);
int		elements_ok(char *map);
int		map_is_surrounded(char *map, int columns, int lines);
int		**aloc_mem(int lines, int columns);
int		choose_char(char c);
int		**convert_map_to_headquarter(char *map, int lines, int columns);
int		there_is_value(int **map, int value, int lines, int columns);
int		modifies_array(int ***map, int value, int lineColocar,
			int columnColocar);
int		puts_value(int ***map, int value, int lines, int columns);
int		flood_fill(int **map, int lines, int columns);
int		map_is_valid(char *map, int **headquarter_map);
int		is_ber(char *filename);
int		complete_deletion(t_mlx_data *mlx);
void	player_position(t_mlx_data **mlx);
void	go_right(t_mlx_data *mlx);
int		handle_key_releasing(int key_code, t_mlx_data *window);
void	*decide_texture(t_mlx_data *mlx, int i, int j);
void	render(t_mlx_data *mlx, int lines, int columns);
void	headquarter_free(t_mlx_data *mlx);
void	init_game(t_mlx_data *mlx);
int		n_collectables(char *map);
void	go_left(t_mlx_data *mlx);
void	go_up(t_mlx_data *mlx);
void	go_down(t_mlx_data *mlx);
