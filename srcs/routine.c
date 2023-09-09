/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:05 by svalente          #+#    #+#             */
/*   Updated: 2023/09/08 21:06:36 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philos)
{
	(void)philos;
	uint64_t	start;
	uint64_t	now;
	
	start = get_time();
	usleep(10000); // value in microseconds but it is not precise
	now = get_time();
	printf("%llu milliseconds have passed since the start\n", now - start);
	return (NULL);
}