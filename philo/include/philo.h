/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:00:18 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/07 16:07:11 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define _DEFAULT_SOURCE

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# include <stdlib.h>  //malloc?

# define INT_MAX 2147483647

# define RESET "\033[0m"
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN    "\033[0;36m"
# define WHITE   "\033[0;37m"

typedef pthread_mutex_t t_mutex;
typedef struct s_table t_table;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}			t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_count;
	bool		full;
	long		lst_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

struct s_table
{
	long	philo_nbr;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	limit_meals;
	long	start_sim;
	bool	end_sim;
	t_fork	*forks;
	t_philo	*philos;
}

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}			t_opcode;

long	ft_atol(const char *str);

bool	parse_and_init(t_table *table,int ac, char **av);

void	*safe_malloc(size_t bytes);
void	safe_thread_handler(phtread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
void	safe_mutex_handler(t_mlx *mutex, t_opcode opcode);

#endif