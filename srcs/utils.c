/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:22:49 by svalente          #+#    #+#             */
/*   Updated: 2023/09/04 22:28:10 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
void	ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}