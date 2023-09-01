/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:43 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/30 17:27:40 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*do_philo(void *ptr)
{
	t_philo		*philo;
	t_control	*data;

	philo = (t_philo *)ptr;
	data = philo->control;
	if (philo->id % 2)
		usleep(200);
	if (data->p_death == FALSE)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_philo(t_control *data)
{
	int	i;

	if (data->number == 1)
		one_philo(data->philo);
	else
	{
		i = 0;
		while (i < data->number)
		{
			pthread_create(&data->philo[i].p_id, NULL, do_philo, (void *)&data->philo[i]);
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
