/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:42:18 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/30 19:06:09 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define C_RED  "\x1B[31m"
# define C_GRN  "\x1B[32m"
# define C_BLU  "\x1B[34m"
# define C_CYN  "\x1B[36m"

# define THINK 1
# define FORK 2
# define EAT 3
# define SLEEP 4
# define DIED 5

typedef struct s_philo
{
	int			id;
	int			state;
	int			l_fork_id;
	int			r_fork_id;
	int			meal_count;
	time_t		meal_history;
	time_t		death_timer;
}				t_philo;

typedef struct s_main
{
	t_philo			*philo;
	int				ph_count;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eatin_lock;
	pthread_mutex_t	write_lock;
}					t_main;

// init
t_main		*init_all(int argc, char **argv);

// check command line arguments
void		check_arguments(int argc, char **argv);

// execution
pthread_t	*execute(t_main *global, void *(fn)(void *));

// utils
long		ft_atoi(const char *str);
time_t		get_time(void);

#endif