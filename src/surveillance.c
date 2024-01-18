/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surveillance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:55:35 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/18 18:53:30 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	surveillance(t_control *data, t_philo *philo)
{
	if (data->p_death == DEATH)
		return (1);
	if (((data->elapsed_time + data->eat) - philo->eat_time) > data->die)
	{
		usleep(200);
		printf("%lld %d died\n",\
				data->elapsed_time, philo->id);
		data->p_death = DEATH;
		return (1);
	}
	return (0);
}
