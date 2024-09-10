/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:07:44 by joao-oli          #+#    #+#             */
/*   Updated: 2024/09/10 12:10:28 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <bits/pthreadtypes.h>
#include "libft_printf/libft.h"

#define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print;
	t_philo			*philos;
	int				n_philos;
}					t_data;

void	*ft_for_monitor(void *void_philos);
void	overall_init(t_data *overall, t_philo *philos, int n_philos);
void	forks_init(pthread_mutex_t *forks, int n_philos);
void	input_init(t_philo *philo, char **argv);
void	philos_init(t_philo *philos, t_data *overall, pthread_mutex_t *forks,
			char **argv);
int		is_dead(t_philo *philo);
int		philosopher_is_dead(t_philo *philo, size_t time_to_die);
int		is_someone_dead(t_philo *philos);
int		all_ate(t_philo *philos);
void	destroy_all(t_data *overall, pthread_mutex_t *forks);
void	think(t_philo *philo);
void	snore(t_philo *philo);
void	eat(t_philo *philo);
void	*routine(void *void_philo);
int		start_dinner(t_data *overall);
size_t	get_curr_time(void);
void	print_message(char *str, t_philo *philo, int id);
int		ft_op_usleep(size_t milliseconds);
int		is_just_numbers(char *s);
int		valid_args(char **argv);
