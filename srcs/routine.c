/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:57 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/18 04:54:35 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_death(t_philo *data)
{
		pthread_mutex_lock(&data->glob[0]);	
		if (data->stop[0] == 0)
		{
				pthread_mutex_unlock(&data->glob[0]);
				return (0);
		}
		pthread_mutex_unlock(&data->glob[0]);	
		return (1);
}

void *is_sleeping(t_philo *info)
{
	if (check_death(info) == 0)
		print_val("is sleeping" , info);
	ft_usleep(info->time_to_sleep * 1000 , info);
	if (check_death(info) == 0)
		print_val("is thinking" , info);
	return NULL;
}

void *is_eating(t_philo *info)
{
		if (check_death(info) == 0)
			print_val("is eating", info);
	info->count++;
	ft_usleep(info->time_to_eat * 1000 , info);	
	return NULL;
}

void *fork_test(t_philo *info)
{
		pthread_mutex_lock(&info->fork[info->left_fork]);
		if (check_death(info) == 0)
		{
			print_val("has taken a fork" , info);		
		}
		while (info->nb_philo == 1)
		{
			if (check_death(info) == 1)
					return NULL;
		}
		pthread_mutex_lock(&info->fork[info->right_fork]);
		if (check_death(info) == 0)
		{
			print_val("has taken a fork" , info);	
		}
		is_eating(info);
		pthread_mutex_unlock(&info->fork[info->left_fork]);
		pthread_mutex_unlock(&info->fork[info->right_fork]);
		info->last_eat[0] = timeval();
		return NULL;
}

void *thread_routine(void *philo_struct)
{
	t_philo *phi;
	
	phi = ((t_philo *)philo_struct);
	if (phi->id % 2 == 0) 
		ft_usleep (phi->time_to_eat * 1000 , phi);
	while (6)
	{
		fork_test(phi);
		if (((phi->count == phi->nb_m_eat) && (phi->nb_philo != 1)) || check_death(phi) == 1)
		{
			phi->compteur[0]++;
			return NULL;
		}
		is_sleeping(phi);
	}
	return NULL;
}
