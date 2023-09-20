/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:15:01 by svalente          #+#    #+#             */
/*   Updated: 2023/09/19 10:52:37 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_num(char *str);
static int	check_limits(char *str);

int	check_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	if (!(ac >= 5 && ac <= 6))
		return (ft_error_msg("Error: Invalid number of arguments\n"));
	while (av[i] && i < ac)
	{
		if (!check_num(av[i]) || !check_limits(av[i]))
			return (ft_error_msg("Error: Invalid arguments\n"));
		if (av[i] == NULL)
			return (ft_error_msg("Error: Invalid arguments\n"));
		i++;
	}
	return (1);
}

static int	check_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (i == 0 && (str[i] == '+'))
			i++;
		if (i == 0 && (str[i] == '-'))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_limits(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
		if (res > INT_MAX || res < INT_MIN)
			return (0);
	}
	return (1);
}
