/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:43 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/22 13:48:56 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*do_philo(void *ptr)
{
	t_philo		*philo;
	t_control	*data;

	philo = (t_philo *)ptr;
	data = philo->control;
	if (philo->id % 2)
		usleep(1000);
	while (data->p_death == FALSE)
	{
		if (data->)
	}
}
