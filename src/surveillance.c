/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surveillance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:55:35 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/25 21:06:47 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	print_die(t_control *data, t_philo *philo)
{
	pthread_mutex_lock(&data->time_mutex);
	printf("%lld %d died\n", \
			data->elapsed_time, philo->id);
	data->p_death = DEATH;
	pthread_mutex_unlock(&data->time_mutex);
}

int	surveillance(t_control *data, t_philo *philo)
{
	long long	time;
	long long	last_time;

	if (data->p_death == DEATH)
	{
		return (1);
	}
	pthread_mutex_lock(&data->time_mutex);
	time = (data->elapsed_time + data->eat) - philo->eat_time;
	pthread_mutex_unlock(&data->time_mutex);
	if (time > data->die)
	{
		pthread_mutex_lock(&philo->control->time_mutex);
		printf("%lld %d is eating\n", \
				philo->control->elapsed_time, philo->id);
		philo->eat_count += 1;
		pthread_mutex_unlock(&philo->control->time_mutex);
		pthread_mutex_lock(&data->time_mutex);
		last_time = data->die - (data->elapsed_time - philo->eat_time);
		pthread_mutex_unlock(&data->time_mutex);
		count_time(data, last_time);
		print_die(data, philo);
		return (1);
	}
	return (0);
}

void	check_eat_count(t_control *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->time_mutex);
	if (data->max_eat == -1)
	{
		pthread_mutex_unlock(&data->time_mutex);
		return ;
	}
	while (i < data->number)
	{
		if (data->philo[i].eat_count < data->max_eat)
		{
			pthread_mutex_unlock(&data->time_mutex);
			return ;
		}
		i++;
	}
	data->eat_fin = 1;
	pthread_mutex_unlock(&data->time_mutex);
}
