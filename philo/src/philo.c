/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:49:27 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 18:54:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_routine(time_t time, t_table *table)
{
	time_t	wakeup;

	wakeup = time_ms() + time;
	while (wakeup > time_ms())
	{
		if (is_sim_end(table))
			break ;
		usleep(100);
	}
}

static void	eat_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo, MSG_FORK, false);
		pthread_mutex_lock(philo->right_fork);
		print_msg(philo, MSG_FORK, false);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_msg(philo, MSG_FORK, false);
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo, MSG_FORK, false);
	}
	print_msg(philo, MSG_EAT, false);
	pthread_mutex_lock(&philo->eat_lock);
	philo->meals_count++;
	philo->lst_meal_time = time_ms();
	pthread_mutex_unlock(&philo->eat_lock);
	sleep_routine(philo->table->time_eat, philo->table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	think_routine(t_philo *philo, bool is_silence)
{
	time_t	since_lst_meal;
	time_t	time_to_die;
	time_t	think_time;

	pthread_mutex_lock(&philo->eat_lock);
	since_lst_meal = time_ms() - philo->lst_meal_time;
	pthread_mutex_unlock(&philo->eat_lock);
	time_to_die = philo->table->time_die - since_lst_meal;
	think_time = (time_to_die - philo->table->time_eat) / 2;
	if (think_time < 0)
		think_time = 0;
	if (is_silence && think_time == 0)
		think_time = SILENCE_THINK_MIN;
	if (think_time > THINK_TIME_MAX)
		think_time = CUT_THINK_TIME;
	if (!is_silence)
		print_msg(philo, MSG_THINK, false);
	sleep_routine(think_time, philo->table);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->eat_lock);
	philo->lst_meal_time = philo->table->start_sim;
	pthread_mutex_unlock(&philo->eat_lock);
	sync_start(philo->table->start_sim);
	if (philo->table->philo_nbr == 1)
	{
		print_msg(philo, MSG_FORK, false);
		sleep_routine(philo->table->time_die, philo->table);
		print_msg(philo, MSG_DIED, false);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		think_routine(philo, true);
	while (!is_sim_end(philo->table))
	{
		eat_routine(philo);
		sleep_routine(philo->table->time_sleep, philo->table);
		print_msg(philo, MSG_SLEEP, false);
		think_routine(philo, false);
	}
	return (NULL);
}
