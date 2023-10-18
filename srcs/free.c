
#include "../include/philo.h"

int	free_resources(t_inf *inf)
{
	int	i;
	
	i = -1;
	while (++i < inf->nb_philo)
	{
		if (pthread_mutex_destroy(&inf->fork[i]) != 0)
			return (1);
	}
	if (pthread_mutex_destroy(&inf->glob[0]) != 0)
		return (1);
	if (pthread_mutex_destroy(&inf->print[0]) != 0)
		return (1);
	printf("free ok\n");
	return (0);
}