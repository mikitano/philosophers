/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:49:27 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 11:07:40 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_routine(time_t time, t_table *table)
{
	time_t	wakeup;

	wakeup = time_ms() + time;
	while (wakeup > time_ms())
	{
		if (!is_sim_end())
	}
}

void	philo_routine(void *data)
