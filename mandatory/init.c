/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:31:07 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/23 18:43:15 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(int philo_count)
{
	t_philo	*phil;
	int	i;

	i = -1;
	phil = malloc(sizeof(t_philo) * philo_count);
	while (++i < philo_count)
		phil = malloc(sizeof(t_philo));
	return (phil);
}

int	*init_all(int argc, char **argv)
{
	t_rule	*rule;

	rule = malloc(sizeof(t_rule));
	rule->ph_count = ft_atoi(argv[1]);
	rule->t_die = ft_atoi(argv[2]);
	rule->t_eat = ft_atoi(argv[3]);
	rule->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rule->must_eat = ft_atoi(argv[5]);
	else
		rule->must_eat = -1;
	rule->philo = philo_init(rule->ph_count);
	return (rule);
}