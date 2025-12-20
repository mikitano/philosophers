/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:00:18 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/20 19:05:25 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _DEFAULT_SOURCE

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define THINK_TIME_MAX 600

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	pthread_t	monitor;
	int			philo_nbr;
	time_t		start_sim;
	time_t		time_die;
	time_t		time_eat;
	time_t		time_sleep;
	int			limit_meals;
	bool		end_sim;
	t_mutex		sim_lock;
	t_philo		*philos;
	t_mutex		*forks;
	t_mutex		write_lock;
}				t_table;

typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	long		meals_count;
	t_mutex		eat_lock;
	time_t		lst_meal_time;
	t_table		*table;
}				t_philo;

//typedef enum e_opcode {
//	LOCK,
//	UNLOCK,
//	INIT,
//	DESTROY,
//	CREATE,
//	JOIN,
//	DETACH
//}						t_opcode;

//typedef struct s_fork
//{
//	t_mutex				fork;
//	int					fork_id;
//}						t_fork;

long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);

bool	parse_and_init(t_table *table, int ac, char **av, int i);

void	data_init(t_table *table);

time_t	time_ms(void);

void	clean_philos(t_philo *philos, int i);
void	clean_forks(t_mutex *forks, int i);

#endif
