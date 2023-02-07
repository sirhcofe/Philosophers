/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:42:18 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 19:17:22 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>

# define C_RED  "\x1B[31m"
# define C_GRN  "\x1B[32m"
# define C_BLU  "\x1B[34m"
# define C_CYN  "\x1B[36m"
# define C_PUR	"\033[35m"
# define C_WHT	"\033[37m"

# define THINK 1
# define FORK 2
# define EAT 3
# define SLEEP 4
# define DIED 5
# define FULL 6

typedef struct s_global
{
	int				died;
	int				ph_fed;
	int				fed_print;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
}					t_global;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				ph_count;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				must_eat;
	time_t			starting_time;
	time_t			meal_history;
	time_t			death_timer;
	pthread_mutex_t	cycle_protect;
	t_global		*rules;
}				t_philo;

// init
t_global	*global_init(char **argv);
t_philo		*philo_init(int argc, char **argv, t_global *rules);

// check command line arguments
void		check_arguments(int argc, char **argv);

// execution and termination
pthread_t	*execute(t_philo *philo, void *(fn)(void *));
void		*philo_cycle(void *argument);
void		*death_timer(void *argument);
void		join_thread(pthread_t *cycle, pthread_t *death, int ph_count);
void		m_wait(time_t target);
void		hard_code(char **argv);

// philo_cycle
int			thinking(t_philo *philo);
int			sleeping(t_philo *philo);
int			eating(t_philo *philo);

// utils
long		ft_atoi(const char *str);
void		ft_free(t_philo *philo, t_global *rules);
time_t		get_time(void);
int			print_message(int status, t_philo *philo);
int			check_anyone_dead(int status, t_philo *philo);

#endif