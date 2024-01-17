/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:12:26 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/17 19:06:20 by fwatanab         ###   ########.fr       */
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
		i++;
	}
}

void	input_args(int argc, char **argv, t_control *data)
{
	int	i;

	data->number = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = 0;
	data->p_death = LIFE;
	data->start_time = get_time();
	data->elapsed_time = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number);
	if (!data->philo)
		return ;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->number);
	if (!data->fork)
		return ;
	i = 0;
	while (i < data->number)
		pthread_mutex_init(&data->fork[i++], NULL);
	input_philo(data);
}
