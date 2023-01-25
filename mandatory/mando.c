/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mando.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:41:36 by chenlee           #+#    #+#             */
/*   Updated: 2023/01/23 18:40:38 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rule	*rule;

	check_arguments(argc, argv);
	rule = init_all(argc, argv);
	
}