/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:35:37 by svalente          #+#    #+#             */
/*   Updated: 2023/09/08 20:55:43 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philos *create_threads(t_data	data)
{
	int			i;
	t_philos	*philos;

	i = 0;
	philos = malloc(sizeof(t_philos) * data.n_philos);
	if (!philos)
		return (NULL);
	while (i++ < data.n_philos)
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]))
			return (NULL);
	i = 0;
	while (i++ < data.n_philos)
		if (pthread_join(philos[i].philo, NULL))
			return (NULL);
	return (philos);
}