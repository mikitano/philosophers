/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:51:53 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 11:07:41 by mkitano          ###   ########.fr       */
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

