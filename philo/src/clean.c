/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:23:40 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 16:08:19 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_philos(t_philo *philos, int i)
{
	while (i--)
		pthread_mutex_destroy(&philos[i].eat_lock);
	free(philos);
}

void	clean_forks(t_mutex *forks, int i)
{
	while (i--)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
}

void	clean_table(t_table *table)
{
	if (!table)
		return ;
	if (table->philos)
		clean_philos(table->philos, table->philo_nbr);
	if (table->forks)
		clean_forks(table->forks, table->philo_nbr);
	pthread_mutex_destroy(&table->sim_lock);
	pthread_mutex_destroy(&table->write_lock);
	free(table);
}
