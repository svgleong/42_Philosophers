/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:15:01 by svalente          #+#    #+#             */
/*   Updated: 2023/09/05 11:53:39 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_num(int ac, char **av);
static long	ft_atol(const char *str);
static int	check_limits(int ac, char **av);

void	check_arguments(int ac, char **av)
{
	(void)av;
	if (!(ac >= 5 && ac <= 6))
		ft_error_msg("Error: Invalid number of arguments\n");
	if (check_num(ac, av))
		if (check_limits(ac, av))
			return ;
	ft_error_msg("Error: Invalid arguments\n");
}

static int	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	res;
	long	sign;
	long	i;

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
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			return (3737373737);
	}
	return (sign * res);
}

static int	check_limits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) == 3737373737)
			return (0);
		i++;
	}
	return (1);
}
