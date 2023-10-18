
#include "../include/philo.h"

int after_routine(t_inf *info)
{
	int i;

	i = -1;
	while (1)
	{
			if (info->stop[0] == 0)
				return (0);
			while (++i < info->nb_philo)
			{
				if (info->stop[0] == 1 && info->phiphi[i]->count == info->nb_philo && info->compteur[0] == info->nb_philo)
				{
					printf("ok pour l'after");
					return (0);	
				}
				i = -1;
			}
		return (1);
	}
	return (1);
}
