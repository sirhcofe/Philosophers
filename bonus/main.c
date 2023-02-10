/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:17 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/10 17:06:33 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->end_signal);
	sem_close(philo->write_lock);
}

int	main(int argc, char **argv)
{
	int			i;
	t_philo		philo;

	check_arguments(argc, argv);
	philo = init_all(argc, argv);
	execute(&philo);
	i = -1;
	while (++i < philo.count)
		sem_post(philo.start_lock);
	terminate(&philo);
	ft_free(&philo);
	kill(0, SIGINT);
	return (0);
}
