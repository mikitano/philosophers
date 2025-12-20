#include "philo.h"

static void	assing_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->right_fork = fork[philo_position];
	philo -> left_fork = forks[(philo_position +1) % philo_nbr];
}

static	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_count = 0;
		philo->table = table;
		assing_forks(philo, table->forks, i);
	}

}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_sim = false;
	table->philos = safe_malloc(sizeof (t_philo) * (table->philo_nbr));
	table->forks = safe_malloc(sizeof (t_fork) * (table->philo_nbr))
	while (i++ < table->philo_nbr)
	{
		safe_mutex_handler(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table); //TODO	
}