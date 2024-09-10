/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-oli <joao-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:26:35 by joao-oli          #+#    #+#             */
/*   Updated: 2024/09/10 11:26:41 by joao-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_for_monitor(void *void_philos)
{
	t_philo	*philos;

	philos = (t_philo *)void_philos;
	while (1)
	{
		if (is_someone_dead(philos) || all_ate(philos))
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t		*forks;
	t_data				overall;
	t_philo				*philos;
	int					n_philos;

	if ((argc != 5 && argc != 6) || !valid_args(argv))
		return (printf("Invalid input\n"), 1);
	n_philos = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * n_philos);
	forks = malloc(sizeof(pthread_mutex_t) * n_philos);
	overall_init(&overall, philos, n_philos);
	forks_init(forks, n_philos);
	philos_init(philos, &overall, forks, argv);
	start_dinner(&overall);
	destroy_all(&overall, forks);
	free(philos);
	free(forks);
	return (0);
}
