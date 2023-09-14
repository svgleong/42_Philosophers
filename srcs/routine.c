/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 16:18:40 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int		eating(t_philo *philo);
void	sleeping(t_philo *philo);

void	*routine(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	phi->last_meal = get_time();
	if (phi->data->n_philos % 2 != 0 && phi->id == phi->data->n_philos)
		print_status(phi, "is thinking", GREEN);
	if (phi->id % 2 == 0)
	{
		print_status(phi, "is thinking", GREEN);
		sleep_time(phi->data->t_eat, philo);
	}
	while (phi->n_meals < phi->data->n_eat && !death_checker(phi))
	{
		eating(phi);
		if (is_dead(phi))
			return (NULL);
		sleeping(phi);
		usleep(1000);
		if (is_dead(phi))
			return (NULL);
		print_status(phi, "is thinking", GREEN);
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
			print_status(philo, "has taken a fork", YELLOW);
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
	int	fork2;

	fork1 = ((philo->id == 1) * (philo->data->n_philos - 1) + \
	((philo->id != 1) * (philo->id - 1)));
	fork2 = (philo->id - 1 - (philo->id != 1));
	lock_fork(&philo->forks[fork1], philo);
	lock_fork(&philo->forks[fork2], philo);
	if (is_dead(philo))
		return (0);
	print_status(philo, "is eating", ORANGE);
	sleep_time(philo->data->t_eat, philo);
	philo->last_meal = get_time();
	unlock_fork(&philo->forks[fork1], philo);
	unlock_fork(&philo->forks[fork2], philo);
	philo->n_meals++;
	return (1);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping", PINK);
	sleep_time(philo->data->t_sleep, philo);
}
