/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/09 20:50:00 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	input_philo(t_control *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		data->philo[i].id = i + 1;
		data->philo[i].fork = 1;
		i++;
	}
}

void	input_args(int argc, char **argv, t_control *data)
{
	data->number = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->fin = ft_atoi(argv[5]);
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!data->philo)
		return ;
	input_philo(data);
}

void	*funk(void *data)
{
	t_control	*tmp;
	int			i;

	i = 0;
	tmp = (t_control *)data;
	while (i < 100000)
	{
		pthread_mutex_lock(&(tmp->mutex));
		tmp->num++;
		i++;
		pthread_mutex_unlock(&(tmp->mutex));
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_control		*data;

	if (argc < 5 || 6 < argc)
		return (error());
	data = (t_control *)malloc(sizeof(t_control));
	if (!data)
		return (1);
	input_args(argc, argv, data);
	if (!data->philo)
		return (1);
	data->num = 0;
	pthread_mutex_init(&(data->mutex), NULL);
	start_philo(data);
	printf("main: %d\n", data->num);
	pthread_mutex_destroy(&(data->mutex));
	free(data);
	return (0);
}
