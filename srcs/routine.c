/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/11 16:21:40 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo);

void	*routine(void *philo)
{	
	t_philo	*curr_philo;
	
	curr_philo = (t_philo *)philo;
	if (curr_philo->id % 2 == 0)
	{
		usleep(1000);
		philo_eat(curr_philo);
	}
	if (curr_philo->id % 2 != 0)
	{
		philo_eat(curr_philo);
	}
	
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	int id;

	id = philo->id;
	pthread_mutex_lock(&philo->forks[id - 1].lock);
	pthread_mutex_lock(&philo->forks[id].lock);
	printf("Philosopher %d is eating\n", philo->id);
	pthread_mutex_unlock(&philo->forks[id - 1].lock);
	pthread_mutex_unlock(&philo->forks[id].lock);
}