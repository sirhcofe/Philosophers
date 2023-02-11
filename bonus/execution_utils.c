/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:43:22 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/11 16:32:53 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	print_message(EAT, philo);
	philo->meal_history = get_time() - philo->starting_time;
	m_wait(philo, philo->t_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->meal_count++;
	if (philo->meal_count == philo->must_eat)
		sem_post(philo->fed_signal);
}

void	thinking(t_philo *philo)
{
	print_message(THINK, philo);
	sem_wait(philo->forks);
	print_message(FORK, philo);
	sem_wait(philo->forks);
	print_message(FORK, philo);
}

void	sleeping(t_philo *philo)
{
	print_message(SLEEP, philo);
	m_wait(philo, philo->t_sleep);
}

/**
 * A m_wait function to overcome the inaccuracy of usleep, where function calls
 * for usleep multiple times with small value parsed as its argument until:
 * 1. philo died
 * 2. target m_wait time has been achieved.
 * 
 * @param target target m_wait time in milliseconds
*/
void	m_wait(t_philo *philo, time_t target)
{
	time_t	base_t;
	time_t	temp_t;

	base_t = get_time();
	while (1)
	{
		usleep(10);
		temp_t = get_time();
		if (temp_t - philo->starting_time - philo->meal_history > philo->t_die)
		{
			print_message(DIED, philo);
			sem_post(philo->end_signal);
			break ;
		}
		if ((temp_t - base_t) >= target)
			break ;
	}
}
