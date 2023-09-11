/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:32:26 by svalente          #+#    #+#             */
/*   Updated: 2023/09/11 12:29:57 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data *data(void)
{
	static t_data data;

	return (&data);
}

t_philo *philos(void)
{
	static t_philo philos;

	return (&philos);
}
