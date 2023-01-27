/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:31:07 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/27 16:04:01 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_main *rule)
{
	int	i;

	i = -1;
	while (++i < rule->ph_count)
	{
		pthread_mutex_init(&(rule->forks[i]), NULL)
	}
}

void	philo_init(t_main *rule)
{
	int		i;
	rule->philo = malloc(sizeof(t_philo) * rule->ph_count);
	i = -1;
	while (++i < rule->ph_count)
	{
		rule->philo[i].id = i;
		rule->philo[i].id = 0;
		rule->philo[i].l_fork_id = i;
		rule->philo[i].r_fork_id = (i + 1) % rule->ph_count;
		rule->philo[i].times_eat = 0;
		rule->philo[i].death_timer = rule->t_die;
	}
}

t_main	*init_all(int argc, char **argv)
{
	t_main	*rule;

	rule = malloc(sizeof(t_main));
	rule->ph_count = (int)ft_atoi(argv[1]);
	rule->t_die = (int)ft_atoi(argv[2]);
	rule->t_eat = (int)ft_atoi(argv[3]);
	rule->t_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		rule->must_eat = (int)ft_atoi(argv[5]);
	else
		rule->must_eat = -1;
	philo_init(rule);
	mutex_init(rule);
	return (rule);
}