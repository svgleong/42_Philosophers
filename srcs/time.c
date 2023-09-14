/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:04:11 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 13:47:21 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((uint64_t)(tv.tv_sec * 1000) + (uint64_t)(tv.tv_usec / 1000));
}

void	sleep_time(uint64_t time, t_philo *philo)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (death_checker(philo))
			return ;
		usleep(time / 10);
	}
	death_checker(philo);
}

uint64_t	time_diff(void)
{
	uint64_t	diff;

	diff = get_time() - data()->start;
	return (diff);
}
