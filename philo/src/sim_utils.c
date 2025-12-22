/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:51:53 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 15:51:34 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_sim_end(t_table *table)
{
	bool	flag;

	pthread_mutex_lock(&table->sim_lock);
	flag = table->end_sim;
	pthread_mutex_unlock(&table->sim_lock);
	return (flag);
}

void	sync_start(time_t start)
{
	while (time_ms() < start)
		;
}

void	print_msg(t_philo *philo, const char *msg, bool is_monitor)
{
	time_t	time;

	pthread_mutex_lock(&philo->table->write_lock);
	time = time_ms() - philo->table->start_sim;
	if (is_sim_end(philo->table))
	{
		if (is_monitor)
			printf("%ld %d %s\n", (long)time, philo->id, msg);
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	printf("%ld %d %s\n", (long)time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_lock);
}
