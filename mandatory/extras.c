/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:06:27 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/30 19:10:21 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(int status, int philo_id)
{
	time_t	time;
	char	*message;

	time = get_time();
	if (status == THINK)
		printf(C_GRN "[%ld] philo_%d is thinking.\n", time, philo_id);
	else if (status == FORK)
		printf(C_CYN "[%ld] philo_%d has taken a fork.\n", time, philo_id);
	else if (status == EAT)
		printf(C_BLU "[%ld] philo_%d is eating.\n", time, philo_id);
	else if (status == SLEEP)
		printf("[%ld] philo_%d is sleeping.\n", time, philo_id);
	else if (status == DIED)
		printf(C_RED "[%ld] philo_%d has died!\n", time, philo_id);
}

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
