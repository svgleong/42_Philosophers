/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:58:38 by svalente          #+#    #+#             */
/*   Updated: 2023/09/14 12:31:16 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	init_struct(int ac, char **av, t_data *data)
{
	t_death	death;

	death.status = 0;
	pthread_mutex_init(&death.lock, NULL); // destroy
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->n_eat = -1;
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = INT_MAX;
	data->start = get_time();
	pthread_mutex_init(&data->print, NULL); // dont forget to destroy
	data->death = death;
	//printf("death status: %d\n", data->death.status);
}

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_fork	*forks;

	if (check_arguments(ac, av) == 0)
		return (0);
	init_struct(ac, av, data());
	forks = init_forks(data());
	if (!forks)
		return (clean_program(NULL, forks));
	philos = malloc(sizeof(t_philo) * data()->n_philos);
	if (!philos)
		return (clean_program(philos, forks));
	init_philos(data(), philos, forks);
	create_threads(philos);
}
