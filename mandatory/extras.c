/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:06:27 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/07 19:23:34 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_thread(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->id]));
		pthread_mutex_unlock(&(philo->rules->forks[(philo->id + 1)
				% philo->ph_count]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->rules->forks[philo->id - 1]));
		pthread_mutex_unlock(&(philo->rules->forks[philo->id]));
	}
	pthread_mutex_unlock(&(philo->rules->write_lock));
}

int	check_everyone_full(int status, t_philo *philo)
{
	int	ret;

	if (status == FULL && philo->rules->fed_print != 1)
	{
		philo->rules->fed_print = 1;
		ret = 0;
	}
	else if (philo->rules->fed_print == 1)
		ret = 1;
	else
		ret = 0;
	return (ret);
}

/**
 * Before printing the messages on screen, checks if either:
 * - One of the philosophers is dead, or
 * - All philosophers have been fed
 * If one of the condition above is true, the message will not be printed, and
 * returns a value of 1 which will then terminate the thread process
 * 
 * @param status print status, ie eating/thinking/etc...
 * @param philo philo struct
*/
int	check_anyone_dead(int status, t_philo *philo)
{
	int	ret;

	if (philo->rules->died == 1)
		ret = 1;
	else if (status == DIED)
	{
		philo->rules->died = 1;
		ret = 0;
	}
	else
		ret = 0;
	return (ret);
}

/**
 * Prints different messages depending on status
 * 
 * @param status print status, ie eating/thinking/etc...
 * @param philo philo struct
*/
int	print_message(int status, t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&(philo->rules->write_lock));
	if (check_anyone_dead(status, philo) || check_everyone_full(status, philo))
	{
		unlock_thread(philo);
		return (1);
	}
	time = get_time() - philo->starting_time;
	if (status == THINK)
		printf(C_GRN "%-8ld %d is thinking\n", time, philo->id);
	else if (status == FORK)
		printf(C_CYN "%-8ld %d has taken a fork\n", time, philo->id);
	else if (status == EAT)
		printf(C_BLU "%-8ld %d is eating\n", time, philo->id);
	else if (status == SLEEP)
		printf(C_WHT "%-8ld %d is sleeping\n", time, philo->id);
	else if (status == DIED)
		printf(C_RED "%-8ld %d died\n", time, philo->id);
	else if (status == FULL)
		printf(C_PUR "%-8ld All philos fed!\n", time);
	else if (status == 0)
		;
	pthread_mutex_unlock(&(philo->rules->write_lock));
	return (0);
}

/**
 * Replication of the atoi function, except function returns long instead of int
 * 
 * @param str string to convert to long
*/
long	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		nbr = (nbr * 10) + (str[i++] - '0');
	nbr = nbr * sign;
	return (nbr);
}
