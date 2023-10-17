/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:41:03 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/16 03:19:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_inf	*info;

	info = malloc(sizeof(t_inf));
	if (!info)
		return (1);
	init_struct(info, argv);
	init_philo(info);
	init_thread(info);
	// if (5 > argc)
	// 	return (1);
	// if (check_ar(argv) == 1)
	// 	return (1);
	if (argc != 5 && argc != 6)
		return (1);
	return (0);
}
