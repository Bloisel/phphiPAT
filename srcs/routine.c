/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:57 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/17 17:53:53 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_death(t_philo *data)
{
		// mutex glob ?
		if (data->stop[0] == 0)
			return (0);
		else
			return (1);
}

void *is_sleeping(t_philo *info)
{
	if (check_death(info) == 0)
		print_val("is sleeping" , info);
	ft_usleep(info->time_to_sleep * 1000);
	if (check_death(info) == 0)
		print_val("is thinking" , info);
	return NULL;
}

void *is_eating(t_philo *info)
{
		if (check_death(info) == 0)
			print_val("is eating", info);
		info->last_eat[0] = timeval();
		info->count++;
		ft_usleep(info->time_to_eat * 1000);
	return NULL;
}

void *fork_test(t_philo *info)
{
		if (info->nb_philo == 1)
		{
			ft_usleep(info->time_to_eat * 1000);
			return NULL;	
		}
		pthread_mutex_lock(&info->fork[info->right_fork]);
		if (check_death(info) == 0)
		{
			print_val("has taken left fork" , info);		
		}
		pthread_mutex_lock(&info->fork[info->left_fork]);
		if (check_death(info) == 0)
		{
			print_val("has taken right fork" , info);	
		}
		is_eating(info);
		pthread_mutex_unlock(&info->fork[info->right_fork]);
		pthread_mutex_unlock(&info->fork[info->left_fork]);
		return NULL;
}

void *thread_routine(void *philo_struct)
{
	t_philo *phi;
	
	phi = ((t_philo *)philo_struct);
	if (phi->id % 2 == 0) // anciemment phinb
		ft_usleep (phi->time_to_eat * 1000);
	while (check_death(phi) == 0)
	{
		printf("id philo = [%d] , left fork  = [%d]\n",phi->id , phi->left_fork);
		printf("id philo = [%d] , right fork = [%d]\n",phi->id ,  phi->right_fork);
		fork_test(phi);
		is_sleeping(phi);
		if (phi->count == phi->nb_m_eat && phi->nb_philo != 1)
		{
				if (++phi->phi_a_eat == phi->nb_philo)
					phi->stop[0] = 1;
				return NULL;
			}
		}
	return NULL;
}
