/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:02:31 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 12:23:17 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	clean_program(t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	if (forks)
	{
		// while (++i < data()->n_philos)
		// 	pthread_mutex_destroy(&forks[i].lock);
		free(forks);
	}
	i = -1;
	if (philos)
	{
		// pthread_mutex_destroy(&data()->print);
		// pthread_mutex_destroy(&data()->death.lock);	
		free(philos);
	}
	return (0);
}
