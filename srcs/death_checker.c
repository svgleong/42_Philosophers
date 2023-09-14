/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:48:31 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 13:48:52 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_dead(t_philo *philo)
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
	if (get_time() - (uint64_t)philo->last_meal >= (uint64_t)philo->data->t_die)
	{
		if (philo->data->death.status == 1)
		{
			pthread_mutex_unlock(&philo->data->death.lock);
			return (1);
		}
		pthread_mutex_lock(&philo->data->print);
		printf("%s%lu %d died\n", RED, time_diff(), philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->data->death.status = 1;
		pthread_mutex_unlock(&philo->data->death.lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
	return (0);
}
