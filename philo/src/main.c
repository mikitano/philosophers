/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:07:22 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/07 18:00:21 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 || ac != 6)
	{
		printf(RED "Argument Error\n" RESET);
		return (1);
	}
	else
	{
		parse_input(&table, av); //TODO
		data_init(&table);  //TODO
		dinner_start(&table); //TODO
		clean(&table); //TODO
	}
	
	return (0);
}
