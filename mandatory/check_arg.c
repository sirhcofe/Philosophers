/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:19:47 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/25 20:40:02 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	}
}
