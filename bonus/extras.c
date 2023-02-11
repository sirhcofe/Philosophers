/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:21:21 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/11 16:40:24 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_dead_when_thinking(t_philo *philo, time_t *ret_time)
{
	time_t	current_time;
	time_t	buffer_time;

	current_time = get_time() - philo->starting_time;
	buffer_time = current_time - philo->meal_history;
	if (buffer_time > philo->t_die)
	{
		*(ret_time) = philo->meal_history + philo->t_die;
		return (DIED);
	}
	else
		return (FORK);
}

int	print_message(int status, t_philo *philo)
{
	time_t	time;

	sem_wait(philo->write_lock);
	time = get_time() - philo->starting_time;
	if (status == FORK)
		status = check_dead_when_thinking(philo, &time);
	if (time <= 2 && time > 0)
		time -= 1;
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
	if (status != DIED)
		sem_post(philo->write_lock);
	else
		sem_post(philo->end_signal);
	return (0);
}

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
