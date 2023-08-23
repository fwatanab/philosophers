/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:12:26 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/22 14:13:55 by fwatanab         ###   ########.fr       */
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
		data->philo[i].l_fork = 1;
		data->philo[i].control = data;
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
		data->end_count = ft_atoi(argv[5]);
	data->p_death = FALSE;
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!data->philo)
		return ;
	data->fork = (mutex_t *)malloc(sizeof(mutex_t));
	if (!data->fork)
		return ;
	input_philo(data);
}
