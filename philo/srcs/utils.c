/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:22:49 by svalente          #+#    #+#             */
/*   Updated: 2023/09/19 10:47:48 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], fd);
		i++;
	}
}

int	ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

void	print_status(t_philo *philo, char *status, char *color)
{
	pthread_mutex_lock(&philo->data->death.lock);
	if (philo->data->death.status == 1)
	{
		pthread_mutex_unlock(&philo->data->death.lock);
		return ;
	}
	pthread_mutex_lock(&philo->data->print);
	printf("%s%lu %d %s\n", color, time_diff(), philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_unlock(&philo->data->death.lock);
}
