/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:10:25 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 19:19:47 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * lol I'm lazy, called when only 1 philo is present, where it's impossible
 * for the philo to eat, and dies
 * 
 * @param argv command line arguments
*/
void	hard_code(char **argv)
{
	int	t_die;

	t_die = (int)(ft_atoi(argv[2]));
	printf(C_GRN "%-8d %d is thinking\n", 0, 0);
	printf(C_CYN "%-8d %d has taken a fork\n", 0, 0);
	m_wait(t_die);
	printf(C_RED "%-8d %d has died!\n", t_die, 0);
}

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
		if (print_message(0, philo) || check_is_dead(philo))
		{
			print_message(DIED, philo);
			break ;
		}
	}
	return (0);
}

void	*philo_cycle(void *argument)
{
	t_philo	*philo;

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
	return (thread);
}
