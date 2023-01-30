/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mando.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:41:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/30 17:41:51 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main		*global;
	pthread_t	*thread;

	check_arguments(argc, argv);
	global = init_all(argc, argv);
	thread = execute(global, &philo_cycle);
}