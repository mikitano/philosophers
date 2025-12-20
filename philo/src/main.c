/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:07:22 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/20 19:13:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	sim_start(t_table *table)
{
	int	i;

	table->start_sim = time_ms() + (table->philo_nbr * 2 * 10);
	i = -1;
	while (++i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				&philo_routine, &table->philos[i]) != 0)
			return (false);
	}
	if (table->philo_nbr > 1)
	{
		if (pthread_create(&table->monitor, NULL, &monitor_routine,
				&table->monitor) != 0)
			return (false);
	}
	return (true);
}

static void	sim_end(t_table *table)
{

}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
	{
		printf(RED "Argument Error\n" RESET);
		return (1);
	}
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
		return (1);
	if (!parse_input(&table, ac, av, 0)
		|| (!forks_init(&table)) || (!philo_init(&table)))
	{
		free(table);
		return (1);
	}
	if (!sim_start(table))
	//	clean(&table); //TODO
	return (0);
}
