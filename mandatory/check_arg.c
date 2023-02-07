/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:19:47 by chenlee           #+#    #+#             */
/*   Updated: 2023/02/04 17:12:44 by chenlee          ###   ########.fr       */
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
		printf("Error: Parameters must contain only integers!\n");
	else if (condition == 3)
		printf("Error: Too many Philosophers!\n");
	else if (condition == 4)
		printf("Error: Negative number detected!\n");
	exit(1);
}

void	check_isnum(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != 0)
	{
		if (line[i] > 57 || line[i] < 48)
			error(2);
	}
}

void	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		error(1);
	else
	{
		while (++i < argc)
			check_isnum(argv[i]);
		if (ft_atoi(argv[1]) > 200)
			error(3);
		if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
			|| ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) < 0))
			error(4);
	}
}
