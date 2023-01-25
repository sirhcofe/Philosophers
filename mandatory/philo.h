/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:42:18 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/23 18:40:56 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			have_eat;
}				t_philo;

typedef	struct s_rule
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
}					t_rule;

// init
int	*init_all(int argc, char **argv);

// check command line arguments
void	check_arguments(int argc, char **argv);

// utils
int		ft_atoi(const char *str);

#endif