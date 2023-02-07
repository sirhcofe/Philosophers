/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:31:07 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 18:44:06 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_free(t_philo *philo, t_global *rules)
{
	int	i;
	int	count;

	count = philo[0].ph_count;
	i = -1;
	while (++i < count)
	{
		pthread_mutex_destroy(&(rules->forks[i]));
		pthread_mutex_destroy(&(philo[i].cycle_protect));
	}
	pthread_mutex_destroy(&(rules->write_lock));
	pthread_mutex_destroy(&(rules->meal_lock));
	free(rules->forks);
	free(rules);
	free(philo);
}

void	mutex_init(t_global *rules, int ph_count)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * ph_count);
	i = -1;
	while (++i < ph_count)
		pthread_mutex_init(&(rules->forks[i]), NULL);
	pthread_mutex_init(&(rules->write_lock), NULL);
	pthread_mutex_init(&(rules->meal_lock), NULL);
}

t_philo	*philo_init(int argc, char **argv, t_global *rules)
{
	t_philo	*philo;
	int		i;
	int		count;

	count = (int)ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * count);
	i = -1;
	while (++i < count)
	{
		philo[i].id = i;
		philo[i].meal_count = 0;
		philo[i].ph_count = count;
		philo[i].t_die = (int)ft_atoi(argv[2]);
		philo[i].t_eat = (int)ft_atoi(argv[3]);
		philo[i].t_sleep = (int)ft_atoi(argv[4]);
		philo[i].starting_time = get_time();
		philo[i].meal_history = get_time();
		if (argc == 6)
			philo[i].must_eat = (int)ft_atoi(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].rules = rules;
		pthread_mutex_init(&(philo[i].cycle_protect), NULL);
	}
	return (philo);
}

t_global	*global_init(char **argv)
{
	t_global	*rules;

	rules = malloc(sizeof(t_global));
	rules->died = 0;
	rules->ph_fed = 0;
	rules->fed_print = 0;
	mutex_init(rules, (int)ft_atoi(argv[1]));
	return (rules);
}
