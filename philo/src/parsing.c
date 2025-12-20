#include "philo.h"

bool	parse_and_init(t_table *table,int ac, char **av)
{
	int	i;

	i = 0
	while (++i < ac)
	{
		if(ft_atol(av[i] <= 0))
		{
			printf(RED "Argument Error\n" RESET);
			return (false);
		}
	}
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat <6e4 || table->time_to_sleep < 6e4)
	{
		printf(RED "Error. Use timestamps major than 60ms\n" RESET);
		return (false);
	}
	if (av[5])
		table->limt_meals = ft_atol(av[5]);
	else
		table->limt_meals = -1;
	return (true);
}
