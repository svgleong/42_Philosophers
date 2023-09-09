/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:58:38 by svalente          #+#    #+#             */
/*   Updated: 2023/09/08 21:05:54 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <philo.h>
#include "../includes/philo.h" // apagar

void	init_struct(int ac, char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->n_eat = -1;
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
}
int	main(int ac, char **av)
{
	t_data		data;
	
	check_arguments(ac, av);
	init_struct(ac, av, &data);
	create_threads(data);
}