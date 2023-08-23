/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/22 19:27:35 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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
	free(data->philo);
	free(data->fork);
	free(data);
	return (0);
}
