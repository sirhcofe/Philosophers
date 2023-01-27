/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:31:47 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/27 16:02:17 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int condition)
{
	if (condition == 1)
	{
		printf("Usage: ./philo <num_of_philo> <time_to_die> <time_to_eat>"
			" <time_to_sleep> <(optional)num_of_times_each_philo_must_eat>\n");
	}
	else if (condition == 2)
		printf("Error: Parameters must contain only numbers!\n");
	else if (condition == 3)
		printf("Error: Too many Philosophers!\n");
	else if (condition == 4)
		printf("Error: Mutex init failed!\n");
	exit(1);
}
