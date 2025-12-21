/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:42:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 12:55:44 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	m_sim_stop(t_table *table)
{
	pthread_mutex_lock(&table->sim_lock);
	table->end_sim = true;
	pthread_mutex_unlock(&table->sim_lock);
}

static bool	check_death(t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->eat_lock);
	time = time_ms() - philo->lst_meal_time;
	pthread_mutex_lock(&philo->eat_lock);
	if (time >= philo->table->time_die)
	{
		m_sim_stop(philo->table);
		print_msg(philo, MSG_DIED, true);
		return (true);
	}
	return (false);
}
