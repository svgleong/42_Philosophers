/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/13 13:51:44 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		eating(t_philo *philo);
void	sleeping(t_philo *philo);

void	*routine(void *philo)
{	
	t_philo	*phi;
	
	phi = (t_philo *)philo;
	if (phi->id % 2 == 0)
		sleep_time(phi->data->t_eat);
	while (phi->n_meals < phi->data->n_eat && !is_dead(phi))//!death_checker(phi))
	{
		eating(phi);
		if (is_dead(phi))
			return (NULL);
		sleeping(phi);
		if (is_dead(phi))
			return (NULL);
		print_status(phi, "is thinking");
	}	
	return (NULL);
}

void	lock_fork(t_fork *fork, t_philo	*philo)
{
	while (!death_checker(philo))
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->status == 1)
		{
			fork->status = 0;
			pthread_mutex_unlock(&fork->lock);
			print_status(philo, "has taken a fork");
			/* pthread_mutex_lock(&philo->data->print);
			printf("%llu %d has taken a fork\n", time_diff(), philo->id);
			pthread_mutex_unlock(&philo->data->print); */
			break ;	
		}
		else
			pthread_mutex_unlock(&fork->lock);
	}
}

void	unlock_fork(t_fork *fork, t_philo	*philo)
{
	while (!death_checker(philo))
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

int	eating(t_philo *philo)
{
	int	fork1;
	int fork2;

	fork1 = ((philo->id == 1) * (philo->data->n_philos - 1) + \
	((philo->id != 1) * (philo->id - 1)));
	fork2 = (philo->id - 1 - (philo->id != 1));
	lock_fork(&philo->forks[fork1], philo);
	lock_fork(&philo->forks[fork2], philo);
	if (is_dead(philo))
		return (1);
	print_status(philo, "is eating");
	/* pthread_mutex_lock(&philo->data->print);
	printf("%llu %d is eating\n", time_diff(), philo->id);
	pthread_mutex_unlock(&philo->data->print); */
	sleep_time(philo->data->t_eat);
	philo->last_meal = get_time();
	unlock_fork(&philo->forks[fork1], philo);
	unlock_fork(&philo->forks[fork2], philo);
	philo->n_meals++;
	return (1);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	/* pthread_mutex_lock(&philo->data->print);
	printf("%llu %d is sleeping\n", time_diff(), philo->id);
	pthread_mutex_unlock(&philo->data->print); */
	sleep_time(philo->data->t_sleep);
}
int is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death.lock);
	if (philo->data->death.status == 1)
	{
		pthread_mutex_unlock(&philo->data->death.lock);	
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
	return (0);
}
int	death_checker(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death.lock);
	//printf("philo death status %d\n", philo->data->death.status);
	if (get_time() - (uint64_t)philo->last_meal > (uint64_t)philo->data->t_die)
	{
		if (philo->data->death.status == 1)
		{
			pthread_mutex_unlock(&philo->data->death.lock);
			return (1);
		}
		print_status(philo, "died");
		/* pthread_mutex_lock(&philo->data->print);
		printf("%llu %d died\n", time_diff(), philo->id);
		pthread_mutex_unlock(&philo->data->print); */
		philo->data->death.status = 1;
		pthread_mutex_unlock(&philo->data->death.lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
	return (0);
}