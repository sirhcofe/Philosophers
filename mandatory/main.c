/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:41:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 19:19:56 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * returns time (in milliseconds) since the start of the UNIX epoch on midnight
 * UTC January 1, 1970, and tv_usec is additional number (in microseconds)
 * elapsed from tv_sec (in seconds).
*/
time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_global	*rules;
	pthread_t	*cycle_thread;
	pthread_t	*death_thread;

	check_arguments(argc, argv);
	if (ft_atoi(argv[1]) == 1)
	{
		hard_code(argv);
		return (0);
	}
	rules = global_init(argv);
	philo = philo_init(argc, argv, rules);
	cycle_thread = execute(philo, &philo_cycle);
	death_thread = execute(philo, &death_timer);
	join_thread(cycle_thread, death_thread, philo[0].ph_count);
	ft_free(philo, rules);
	return (0);
}
