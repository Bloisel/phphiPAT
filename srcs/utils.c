/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:40:54 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/17 22:02:32 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long timeval() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long milis , t_philo *info)
{
	long long	time;

	time = timeval() * 1000;
	while (1)
	{
		if (check_death(info) == 1)
			break ;
		usleep(50);
		if (timeval() * 1000 - time >= milis)
			break ;
	}
}

int	ft_atoi_s(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res);
}

int	check_ar(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	print_val(char *str, t_philo *phil)
{
long	ms;

// pthread_mutex_lock(&phil->glob[0]);
	ms = 0;
	ms = (timeval() - phil->time_to_start);
if (ms >= 0 && (phil->stop[0] == 0))
	printf("%ld, %d, %s\n", ms, phil->id, str);
// pthread_mutex_unlock(&phil->glob[0]);
}