/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:56:22 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/09 19:53:52 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sems_init(t_philo *philo)
{
	sem_unlink("sem_start_lock");
	sem_unlink("sem_forks");
	sem_unlink("sem_write_lock");
	sem_unlink("sem_end_signal");
	sem_unlink("sem_fed_signal");
	philo->start_lock = sem_open("sem_start_lock", O_CREAT, 0664, 0);
	philo->forks = sem_open("sem_forks", O_CREAT, 0664, philo->count);
	philo->write_lock = sem_open("sem_write_lock", O_CREAT, 0664, 1);
	philo->end_signal = sem_open("sem_end_signal", O_CREAT, 0664, 0);
	philo->fed_signal = sem_open("sem_fed_signal", O_CREAT, 0664, 0);
}

t_philo	init_all(int argc, char **argv)
{
	t_philo	philo;

	philo.count = (int)ft_atoi(argv[1]);
	philo.meal_count = 0;
	philo.starting_time = get_time();
	philo.meal_history = philo.starting_time;
	philo.t_die = (int)ft_atoi(argv[2]);
	philo.t_eat = (int)ft_atoi(argv[3]);
	philo.t_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		philo.must_eat = (int)ft_atoi(argv[5]);
	else
		philo.must_eat = -1;
	sems_init(&philo);
	return (philo);
}
