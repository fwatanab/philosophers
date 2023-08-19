#include "../inc/philosophers.h"

void	start_philo(t_control *data)
{
	int	i;

	if (data->number == 1)
		printf("number == 1\n");//one_philo(data->philo);
	else
	{
		i = 0;
		while (i < data->number)
		{
			pthread_create(&data->philo[i].p_id, NULL, funk, (void *)data);
			i++;
		}
		i = 0;
		while (i < data->number)
		{
			pthread_join(data->philo[i].p_id, NULL);
			i++;
		}
	}
}
