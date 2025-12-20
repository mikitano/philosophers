/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:23:40 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/20 18:46:49 by mkitano          ###   ########.fr       */
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
