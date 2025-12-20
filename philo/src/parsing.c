/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:07:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/20 16:22:31 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_and_init(t_table *table, int ac, char **av, int i)
{
	while (++i < ac)
	{
		if (ft_atol(av[i] <= 0))
		{
			printf(RED "Argument Error\n" RESET);
			return (false);
		}
	}
	table->philo_nbr = (int)ft_atol(av[1]);
	table->time_die = ft_atol(av[2]);
	table->time_eat = ft_atol(av[3]);
	table->time_sleep = ft_atol(av[4]);
	if (av[5])
		table->limit_meals = (int)ft_atol(av[5]);
	if (pthread_mutex_init(&table->write_lock, NULL) != 0
		|| pthread_mutex_init(&table->sim_lock, NULL) != 0)
		return (false);
	return (true);
}
