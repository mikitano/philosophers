/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:52:18 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/20 18:47:45 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


bool	philo_init(t_table *table)
{
	int		i;

	table->philos = ft_calloc(table->philo_nbr, sizeof(t_philo));
	if (!table->philos)
		return (false);
	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_count = 0;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		if (pthread_mutex_init(&table->philos[i].eat_lock, NULL) != 0)
		{
			clean_philos(table->philos, i);
			return (false);
		}
	}
	return (true);
}

bool	forks_init(t_table *table)
{
	int	i;

	table->end_sim = false;
	table->forks = ft_calloc(table->philo_nbr, sizeof(t_mutex));
	if (!table->forks)
		return (false);
	i = -1;
	while (++i < table->forks)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			clean_forks(table->forks, i);
			return (false);
		}
	}
	return (true);
}
