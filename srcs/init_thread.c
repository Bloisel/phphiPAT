/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:55:48 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/18 02:55:48 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_thread(t_inf *info)
{
	int i;

	i = 0;
	pthread_t t[info->nb_philo];
	while (i < info->nb_philo)
	{
		pthread_create(&t[i] , NULL , thread_routine , info->phiphi[i]);  
		i++;
		usleep(50);
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
					if (info->time_to_die <= (timeval() - info->phiphi[i]->last_eat[0]))
					{
						info->phiphi[i]->stop[0] = 1;
						print_val("is dead" , info->phiphi[i]);
						return ; 
					}
			}
			i = -1;
	}
	return ;
}