/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:58:38 by svalente          #+#    #+#             */
/*   Updated: 2023/09/11 16:11:17 by svalente         ###   ########.fr       */
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
	data->start = get_time();
}
int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;
	t_fork	*forks;
	
	check_arguments(ac, av);
	init_struct(ac, av, &data);
	forks = init_forks(&data);
	if(!forks)
		return (0); // fazer function error_handler
	philos = malloc(sizeof(t_philo) * data.n_philos);
	if (!philos)
		return (0);
	init_philos(&data, philos, forks);
	create_threads(philos);
	if(!philos)
		return (0); // fazer function error_handler
}