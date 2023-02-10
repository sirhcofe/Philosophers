/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:53:00 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/10 12:41:07 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * every child process will each run this function, where function will first
 * wait for all process to be fully created, then through sem_post in main
 * process will start the simulation of these child processes simultaneously
 * 
 * @param philo struct containing individual philo information with global rules
*/
void	create_child_process(t_philo *philo)
{
	sem_wait(philo->start_lock);
	philo->starting_time = get_time();
	philo->meal_history = philo->starting_time;
	if (philo->id % 2 == 0)
		usleep(42);
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	exit(0);
}

/**
 * main execution function which creates child processes through fork(),
 * where the function call will then:
 * - returns zero inside successfully created child processes
 *     -> each child process will then run their respective simulations
 * - returns non-zero pid outisde main parent process
 *     -> store pid values of child processes
 * 
 * @param philo struct containing individual philo information with global rules
*/
void	execute(t_philo *philo)
{
	int	pid;
	int	i;

	i = -1;
	while (++i < philo->count)
	{
		pid = fork();
		if (pid == 0)
		{
			philo->id = i;
			create_child_process(philo);
			break ;
		}
	}
}

void	*end_wait(void *argument)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)argument;
	sem_wait(philo->end_signal);
	i = -1;
	while (++i < philo->count)
		sem_post(philo->fed_signal);
	return (0);
}

void	*full_wait(void *argument)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)argument;
	i = -1;
	while (++i < philo->count)
		sem_wait(philo->fed_signal);
	sem_post(philo->end_signal);
	return (0);
}

/**
 * function call from main process, responsible for checking for the death of
 * any philo (child processes) or all philo has been fed. Since sem_wait is
 * used to wait for signal from the child processes, threadings must be used
 * to account for 2 sem_wait calls
 * 
 * @param philo struct containing individual philo information with global rules
*/
void	terminate(t_philo *philo)
{
	pthread_t	end;
	pthread_t	full;

	pthread_create(&end, NULL, &end_wait, (void *)philo);
	pthread_create(&full, NULL, &full_wait, (void *)philo);
	pthread_join(end, NULL);
	pthread_join(full, NULL);
}
