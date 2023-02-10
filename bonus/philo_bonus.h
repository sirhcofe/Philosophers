/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/09 20:20:16 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>

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

typedef struct s_philo
{
	int		id;
	int		count;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		must_eat;
	int		meal_count;
	time_t	meal_history;
	time_t	starting_time;
	sem_t	*start_lock;
	sem_t	*forks;
	sem_t	*write_lock;
	sem_t	*end_signal;
	sem_t	*fed_signal;
}			t_philo;

// error checking
void		check_arguments(int argc, char **argv);

// init
t_philo		init_all(int argc, char **argv);

// execution
void		execute(t_philo *philo);
void		eating(t_philo *philo);
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
void		m_wait(t_philo *philo, time_t target);

// termination
void		terminate(t_philo *philo);

// extras
long		ft_atoi(const char *str);
time_t		get_time(void);
int			print_message(int status, t_philo *philo);

#endif