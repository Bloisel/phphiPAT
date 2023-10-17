/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:55:48 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/17 16:11:59 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_thread(t_inf *info)
{
	int i;
	pthread_t t[info->nb_philo];
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_create(&t[i] , NULL , thread_routine , info->phiphi[i]);  
		i++;
	}
	i = 0;
	while(i < info->nb_philo)
	{
		pthread_detach(t[i]);
		i++;	
	}
	i = -1;
	while (1)
	{
			while (++i < info->nb_philo)
			{
					if (info->time_to_die < timeval() - info->phiphi[i]->last_eat[0])
					{
						print_val("is dead" , info->phiphi[i]);
						info->phiphi[i]->stop[0] = 1;
						return ;
					}
			}
			i = -1;
	}
	return ;
}