/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:31:07 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/30 17:43:13 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_main *global)
{
	int	i;

	i = -1;
	while (++i < global->ph_count)
	{
		pthread_mutex_init(&(global->forks[i]), NULL);
	}
}

void	philo_init(t_main *global)
{
	int		i;
	global->philo = malloc(sizeof(t_philo) * global->ph_count);
	i = -1;
	while (++i < global->ph_count)
	{
		global->philo[i].id = i;
		global->philo[i].id = 0;
		global->philo[i].l_fork_id = i;
		global->philo[i].r_fork_id = (i + 1) % global->ph_count;
		global->philo[i].meal_count = 0;
		global->philo[i].death_timer = global->t_die;
	}
}

t_main	*init_all(int argc, char **argv)
{
	t_main	*global;

	global = malloc(sizeof(t_main));
	global->ph_count = (int)ft_atoi(argv[1]);
	global->t_die = (int)ft_atoi(argv[2]);
	global->t_eat = (int)ft_atoi(argv[3]);
	global->t_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		global->must_eat = (int)ft_atoi(argv[5]);
	else
		global->must_eat = -1;
	philo_init(global);
	mutex_init(global);
	return (global);
}