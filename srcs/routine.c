/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:57 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/18 05:33:06 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_end(t_philo *data)
{
		pthread_mutex_lock(&data->glob[0]);	
		if (data->stop[0] == 1)
		{
				pthread_mutex_unlock(&data->glob[0]);
				return (1);
		}
		if (data->count == data->nb_m_eat)
		{
			pthread_mutex_unlock(&data->glob[0]);
			return (1);	
		}
		pthread_mutex_unlock(&data->glob[0]);	
		return (0);
}

void *is_sleeping(t_philo *info)
{
	if (check_end(info) == 0)
		print_val("is sleeping" , info);
	ft_usleep(info->time_to_sleep * 1000 , info);
	if (check_end(info) == 0)
		print_val("is thinking" , info);
	return NULL;
}

void *is_eating(t_philo *info)
{
		if (check_end(info) == 0)
			print_val("is eating", info);
	if (info->nb_m_eat != -50)
		info->count++;
	ft_usleep(info->time_to_eat * 1000 , info);	
	return NULL;
}

void *fork_test(t_philo *info)
{
		pthread_mutex_lock(&info->fork[info->left_fork]);
		if (check_end(info) == 0)
		{
			print_val("has taken a fork" , info);		
		}
		while (info->nb_philo == 1)
		{
			if (check_end(info) == 1)
					return NULL;
		}
		pthread_mutex_lock(&info->fork[info->right_fork]);
		if (check_end(info) == 0)
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
	while (check_end(phi) != 1)
	{
		fork_test(phi);
		is_sleeping(phi);
	}
	phi->compteur[0]++;
	return NULL;
}
