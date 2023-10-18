/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:35:20 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/18 05:31:34 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct t_phil
{
	pthread_mutex_t *fork;
	long long *last_eat; 
	
	int *stop; 

	int id;
	

	int *compteur;
	int nb_m_eat;
	int phi_a_eat;
	int count;

	int nb_philo;	
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;

	int left_fork;
	int right_fork;

	long long time_to_start;

	pthread_mutex_t *print;
	pthread_mutex_t *glob;

}   t_philo;

typedef struct t_info
{
	int nb_philo;
	int time_to_eat;
	int time_to_die;
	int time_to_sleep;
	int phi_a_eat;

	int nb_m_eat;

	int *compteur;
	long long time_to_start;
	int *stop;

	pthread_mutex_t *fork;
	pthread_mutex_t *print;
	pthread_mutex_t *glob;

	t_philo **phiphi;
}   t_inf;

long long timeval();
void	ft_usleep(long long milis , t_philo *info);
void init_phiphi(t_inf *info);
void init_philo(t_inf *info);
void init_mutex(t_inf *info);
void	init_struct(t_inf *info, char **argv);
void *thread_routine(void *philo_struct);
void init_thread(t_inf *info);
int	ft_atoi_s(char *str);
int	checkar(char **argv);
void init_thread(t_inf *info);
int check_end(t_philo *data);
void	print_val(char *str, t_philo *info);
int	free_resources(t_inf *inf);
int after_routine(t_inf *info);

#endif