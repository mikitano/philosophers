#include "philo.h"

void	parse_input(t_table *table, char **av)
{
	if ((table->philo_nbr = ft_atol(av[1])) <= 0)
	{
		printf(RED "Argument Error\n" RESET);
		return ;
	}

}
