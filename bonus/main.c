/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:17 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/11 16:28:00 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	usleep(t_die * 1000);
	printf(C_RED "%-8d %d has died!\n", t_die, 0);
}

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
	if (ft_atoi(argv[1]) == 1)
	{
		hard_code(argv);
		return (0);
	}
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
