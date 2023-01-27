/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mando.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:41:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/27 20:10:56 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	*rule;

	check_arguments(argc, argv);
	rule = init_all(argc, argv);
	execute(rule);
}