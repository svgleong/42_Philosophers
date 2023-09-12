/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:04:11 by svalente          #+#    #+#             */
/*   Updated: 2023/09/12 14:06:48 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "../includes/philo.h" // apagar

/* struct timeval
{
	time_t		tv_sec; 	// seconds from January 1, 1970
							// specific point in time from which all other times are measured
	suseconds_t	tv_usec;	// number of microseconds that have passed 
							// within the current second at the time when a gettimeofday call is made
}; 
1 sec = 1 000 000 microsec
1 sec = 1 000 milisec

usleep accepts value in microseconds --- 10 000 microsec == 10 milisec

uint64_t because of large values, especially if you're measuring time over a long duration
*/

uint64_t	get_time(void) // returns time in miliseconds 1 sec = 1000 mili
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((uint64_t)(tv.tv_sec * 1000) + (uint64_t)(tv.tv_usec / 1000));
}


void	sleep_time(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 10);
}

uint64_t	time_diff(void)
{
	uint64_t diff = get_time() - data()->start;
	return (diff);
}
/* void	example(void)
{
	uint64_t	start;
	uint64_t	now;
	
	start = get_time();
	usleep(10000); // value in microseconds but it is not precise
	now = get_time();
	printf("%llu milliseconds have passed since the start\n", now - start);
} */