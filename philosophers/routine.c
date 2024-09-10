/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:26:54 by joao-oli          #+#    #+#             */
/*   Updated: 2024/09/10 11:26:55 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	snore(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_op_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("took a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_op_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("took a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_curr_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_op_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		ft_op_usleep(1);
	while (!is_dead(philo))
	{
		eat(philo);
		snore(philo);
		think(philo);
	}
	return (NULL);
}

int	start_dinner(t_data *overall)
{
	pthread_t	monitor;
	int			i;

	pthread_create(&monitor, NULL, &ft_for_monitor, overall->philos);
	i = 0;
	while (i < overall->philos[0].num_of_philos)
	{
		pthread_create(&overall->philos[i].philo, NULL, &routine,
			&overall->philos[i]);
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < overall->philos[0].num_of_philos)
	{
		pthread_join(overall->philos[i].philo, NULL);
		i++;
	}
	return (0);
}
