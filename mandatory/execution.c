/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:10:25 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 14:50:57 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_dead(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&(philo->cycle_protect));
	if (get_time() - philo->starting_time - philo->meal_history
		> philo->t_die)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&(philo->cycle_protect));
	return (ret);
}

void	*death_timer(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)(argument);
	while (1)
	{
		if (check_is_dead(philo))
		{
			print_message(DIED, philo);
			break ;
		}
	}
	return (0);
}

void	*philo_cycle(void *argument)
{
	t_philo *philo;

	philo = (t_philo *)(argument);
	while (1)
	{
		if (thinking(philo))
			break ;
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
	}
	return (0);
}

pthread_t	*execute(t_philo *philo, void *(fn)(void *))
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * philo[0].ph_count);
	i = -1;
	while (++i < philo[0].ph_count)
		pthread_create(&(thread[i]), NULL, fn, (void *)(&(philo[i])));
	return(thread);
}

/**
 * Function to terminate threads
 * 
 * @param cycle the main threads responsible for monitoring eat/sleep/think
 * @param death the death threads responsible for monitoring philos death
 * @param ph_count total number of philosophers
*/
void	join_thread(pthread_t *cycle, pthread_t *death, int ph_count)
{
	int	i;

	i = -1;
	while (++i < ph_count)
	{
		pthread_join(cycle[i], NULL);
		pthread_join(death[i], NULL);
	}
	free(cycle);
	free(death);
}