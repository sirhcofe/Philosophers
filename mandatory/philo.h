/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:42:18 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/27 16:03:48 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			state;
	int			l_fork_id;
	int			r_fork_id;
	int			times_eat;
	time_t		death_timer;
}				t_philo;

typedef	struct s_main
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
t_main	*init_all(int argc, char **argv);

// check command line arguments
void	check_arguments(int argc, char **argv);

// utils
long	ft_atoi(const char *str);
void	error(int condition);
time_t	get_time(void);

#endif