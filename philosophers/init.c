/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:27:04 by joao-oli          #+#    #+#             */
/*   Updated: 2024/09/10 11:27:06 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	overall_init(t_data *overall, t_philo *philos, int n_philos)
{
	overall->dead_flag = 0;
	overall->philos = philos;
	overall->n_philos = n_philos;
	pthread_mutex_init(&overall->print, NULL);
	pthread_mutex_init(&overall->dead_lock, NULL);
	pthread_mutex_init(&overall->meal_lock, NULL);
}

void	forks_init(pthread_mutex_t *forks, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	input_init(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	philos_init(t_philo *philos, t_data *overall, pthread_mutex_t *forks,
					char **argv)
{
	int	i;

	i = 0;
	while (i < overall->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		input_init(&philos[i], argv);
		philos[i].start_time = get_curr_time();
		philos[i].last_meal_time = get_curr_time();
		philos[i].print = &overall->print;
		philos[i].dead_lock = &overall->dead_lock;
		philos[i].meal_lock = &overall->meal_lock;
		philos[i].dead = &overall->dead_flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[overall->n_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}
