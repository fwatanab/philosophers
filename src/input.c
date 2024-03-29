/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:12:26 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/24 19:24:07 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	input_philo(t_control *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		data->philo[i].id = i + 1;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->number;
		data->philo[i].control = data;
		data->philo[i].eat_count = 0;
		data->philo[i].eat_time = 0;
		i++;
	}
}

static void	init_mutex(t_control *data)
{
	int	i;

	data->fork = malloc(sizeof(pthread_mutex_t) * data->number);
	if (!data->fork)
	{
		free(data->philo);
		free(data);
		return ;
	}
	i = 0;
	while (i < data->number)
		pthread_mutex_init(&data->fork[i++], NULL);
	pthread_mutex_init(&data->surveil_mutex, NULL);
	pthread_mutex_init(&data->time_mutex, NULL);
}

void	input_args(int argc, char **argv, t_control *data)
{
	data->number = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->p_death = LIFE;
	data->eat_fin = 0;
	data->start_time = get_time();
	data->elapsed_time = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number);
	if (!data->philo)
	{
		free(data);
		return ;
	}
	init_mutex(data);
	input_philo(data);
}
