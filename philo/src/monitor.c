/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:42:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 18:55:10 by mkitano          ###   ########.fr       */
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

	time = time_ms() - philo->lst_meal_time;
	if (time >= philo->table->time_die)
	{
		m_sim_stop(philo->table);
		print_msg(philo, MSG_DIED, true);
		return (true);
	}
	return (false);
}

static bool	check_stop_condition(t_table *table, int i)
{
	bool	full;

	full = true;
	while (++i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->philos[i].eat_lock);
		if (check_death(&table->philos[i]))
		{
			pthread_mutex_unlock(&table->philos[i].eat_lock);
			return (true);
		}
		if (table->limit_meals
			&& (int)table->philos[i].meals_count < table->limit_meals)
			full = false;
		pthread_mutex_unlock(&table->philos[i].eat_lock);
	}
	if (table->limit_meals && full)
	{
		m_sim_stop(table);
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	sync_start(table->start_sim);
	while (1)
	{
		if (check_stop_condition(table, -1))
			return (NULL);
		usleep(1e3);
	}
	return (NULL);
}
