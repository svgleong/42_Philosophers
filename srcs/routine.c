/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/12 18:44:44 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

void	*routine(void *philo)
{	
	t_philo	*curr_philo;
	
	curr_philo = (t_philo *)philo;
	if (curr_philo->id % 2 == 0)
		usleep(curr_philo->data->t_eat);
	while (curr_philo->n_meals < curr_philo->data->n_eat)
	{
		eating(curr_philo);
		sleeping(curr_philo);
		pthread_mutex_lock(&curr_philo->data->print);
		printf("%llu %d is thinking\n", time_diff(), curr_philo->id);
		pthread_mutex_unlock(&curr_philo->data->print);
	}
	
	return (NULL);
}

void	lock_fork(t_fork *fork, t_philo	*philo)
{
	while (1)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->status == 1)
		{
			fork->status = 0;
			pthread_mutex_unlock(&fork->lock);
			pthread_mutex_lock(&philo->data->print);
			printf("%llu %d has taken a fork\n", time_diff(), philo->id);
			pthread_mutex_unlock(&philo->data->print);
			break ;	
		}
		else
			pthread_mutex_unlock(&fork->lock);
	}
}

void	unlock_fork(t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->status == 0)
		{
			fork->status = 1;
			pthread_mutex_unlock(&fork->lock);
			break ;	
		}
		else
			pthread_mutex_unlock(&fork->lock);
	}	
}

void	eating(t_philo *philo)
{
	int	fork1;
	int fork2;

	fork1 = ((philo->id == 1) * (philo->data->n_philos - 1) + \
	((philo->id != 1) * (philo->id - 1)));
	fork2 = (philo->id - 1 - (philo->id != 1));
	lock_fork(&philo->forks[fork1], philo);
	lock_fork(&philo->forks[fork2], philo);
	pthread_mutex_lock(&philo->data->print);
	printf("%llu %d is eating\n", time_diff(), philo->id);
	pthread_mutex_unlock(&philo->data->print);
	sleep_time(philo->data->t_eat);
	unlock_fork(&philo->forks[fork1]);
	unlock_fork(&philo->forks[fork2]);
	philo->n_meals++;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%llu %d is sleeping\n", time_diff(), philo->id);
	pthread_mutex_unlock(&philo->data->print);
	sleep_time(philo->data->t_sleep);
}
