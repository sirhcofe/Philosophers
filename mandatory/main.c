/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:41:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/04 23:36:15 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_global	*rules;
	pthread_t	*cycle_thread;
	pthread_t	*death_thread;

	check_arguments(argc, argv);
	rules = global_init(argv);
	philo = philo_init(argc, argv, rules);
	cycle_thread = execute(philo, &philo_cycle);
	death_thread = execute(philo, &death_timer);
	join_thread(cycle_thread, death_thread, philo[0].ph_count);
	ft_free(philo, rules);
	return (0);
}
