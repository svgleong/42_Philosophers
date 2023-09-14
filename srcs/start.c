/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:35:37 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 11:58:49 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_philo	*philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].data->n_philos)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (0);
	}
	i = -1;
	while (++i < philos[0].data->n_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (0);
	clean_program(philos, philos->forks);
	return (1);
}

t_fork	*init_forks(t_data *data)
{
	int		i;
	t_fork	*forks;

	i = -1;
	forks = malloc(sizeof(t_fork) * data->n_philos);
	while (++i < data->n_philos)
	{
		forks[i].status = 1;
		if (pthread_mutex_init(&forks[i].lock, NULL))
			return (NULL);
	}
	return (forks);
}

void	init_philos(t_data *data, t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		philos[i].data = data;
		philos[i].forks = forks;
		philos[i].id = i + 1;
		philos[i].n_meals = 0;
		philos[i].last_meal = get_time();
	}
}
