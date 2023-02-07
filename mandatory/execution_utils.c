/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:06:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 19:10:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_fed(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(philo->rules->meal_lock));
	philo->meal_count++;
	if (philo->meal_count == philo->must_eat)
		philo->rules->ph_fed++;
	if (philo->rules->ph_fed == philo->ph_count)
	{
		if (print_message(FULL, philo))
			ret = 1;
	}
	pthread_mutex_unlock(&(philo->rules->meal_lock));
	return (ret);
}

int	eating(t_philo *philo)
{
	if (print_message(EAT, philo))
		return (1);
	pthread_mutex_lock(&(philo->cycle_protect));
	philo->meal_history = get_time() - philo->starting_time;
	if (philo->must_eat != -1 && check_if_fed(philo))
	{
		pthread_mutex_unlock(&(philo->cycle_protect));
		return (1);
	}
	m_wait(philo->t_eat);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->id]));
		pthread_mutex_unlock(&(philo->rules->forks[(philo->id + 1)
				% philo->ph_count]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->id - 1]));
		pthread_mutex_unlock(&(philo->rules->forks[philo->id]));
	}
	pthread_mutex_unlock(&(philo->cycle_protect));
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_message(SLEEP, philo))
		return (1);
	m_wait(philo->t_sleep);
	return (0);
}

/**
 * All philos are set to thinking first, and:
 * - The philos with even id number will attempt to pick up their own fork
 * - The philos with odd id number will attempt to pick up (id - 1)'s fork
 * whichever philo who successfully picked up the fork will then:
 * - pick up (id + 1)'s fork (if id is even)
 * - pick up (id)'s fork (if id is odd)
 * 
 * @param philo struct containing datas for each philo, with general rules
*/
int	thinking(t_philo *philo)
{
	if (print_message(THINK, philo))
		return (1);
	if (philo->id % 2 == 0)
	{
		if (print_message(0, philo))
			return (1);
		pthread_mutex_lock(&(philo->rules->forks[philo->id]));
		if (print_message(FORK, philo))
			return (1);
		pthread_mutex_lock(&(philo->rules->forks[(philo->id + 1)
				% philo->ph_count]));
	}
	else if (philo->id % 2 != 0)
	{
		if (print_message(0, philo))
			return (1);
		pthread_mutex_lock(&(philo->rules->forks[philo->id - 1]));
		if (print_message(FORK, philo))
			return (1);
		pthread_mutex_lock(&(philo->rules->forks[philo->id]));
	}
	if (philo->ph_count >= 2 && print_message(FORK, philo))
		return (1);
	return (0);
}

/**
 * A m_wait function to overcome the inaccuracy of usleep, where function calls
 * for usleep multiple times with small value parsed as its argument until
 * target m_wait time has been achieved.
 * 
 * @param target target m_wait time in milliseconds
*/
void	m_wait(time_t target)
{
	time_t	base_t;
	time_t	temp_t;

	base_t = get_time();
	while (1)
	{
		usleep(100);
		temp_t = get_time();
		if ((temp_t - base_t) >= target)
			break ;
	}
}
