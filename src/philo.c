/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:43 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/22 16:57:11 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*do_philo(void *ptr)
{
	t_philo		*philo;
	t_control	*data;
	int			p_death;
	int			eat_fin;

	philo = (t_philo *)ptr;
	data = philo->control;
	if (philo->id % 2)
		usleep(2000);
//	while (data->p_death == LIFE && !data->eat_fin)
//	{
//		philo_eat(philo);
//		philo_sleep(philo);
//		philo_think(philo);
//	}
	while (1)
	{
		pthread_mutex_lock(&data->time_mutex);
		p_death = data->p_death;
		eat_fin = data->eat_fin;
		pthread_mutex_unlock(&data->time_mutex);
		
		if (p_death != LIFE || eat_fin)
			break;
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
			pthread_create(&data->philo[i].p_id, \
					NULL, do_philo, (void *)&data->philo[i]);
			i++;
		}
		i = 0;
		while (i < data->number)
		{
			pthread_join(data->philo[i].p_id, NULL);
			i++;
		}
	}
	i = 0;
	while (i < data->number)
		pthread_mutex_destroy(&data->fork[i++]);
}
