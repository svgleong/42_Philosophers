/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:49:23 by svalente          #+#    #+#             */
/*   Updated: 2023/09/05 12:12:32 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------ Includes ------------
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

//------------ Defines --------------

//------------ Structs --------------

typedef struct s_data
{
	int	n_philos;
	int	t_die;
	int	t_eat;
	int	t_sleep;
}	t_data;

//------------ Prototypes -----------

void	check_arguments(int ac, char **av);

void	ft_putstr_fd(char *str, int fd);
void	ft_error_msg(char *msg);


#endif