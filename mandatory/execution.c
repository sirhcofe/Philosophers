/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:10:25 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/30 19:20:40 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action(t_philo *philo)
{
	philo->meal_history = get_time();
	while (1)
	{
		if (thinking(philo) || eating(philo) || sleeping(philo))
			break ;
	}
}

pthread_t	*execute(t_main *global, void *(fn)(void *))
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * global->ph_count);
	i = -1;
	while (++i < global->ph_count)
		pthread_create(&(thread[i]), NULL, fn, (void *)(&(global->philo[i])));
	return(thread);
}

//  ____  _   _  ____  __    _____  ___  _____  ____  _   _  ____  ____  ___ 
// (  _ \( )_( )(_  _)(  )  (  _  )/ __)(  _  )(  _ \( )_( )( ___)(  _ \/ __)
//  )___/ ) _ (  _)(_  )(__  )(_)( \__ \ )(_)(  )___/ ) _ (  )__)  )   /\__ \
// (__)  (_) (_)(____)(____)(_____)(___/(_____)(__)  (_) (_)(____)(_)\_)(___/
