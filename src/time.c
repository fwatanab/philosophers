/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:30:44 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/29 18:27:36 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	get_time(void)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000LL + now_time.tv_usec / 1000LL);
}

void	count_time(t_control *data, int ms_time)
{
	long long	start_time;
	long long	now_time;

	now_time = 0;
	start_time = get_time();
	while ((now_time - start_time) < ms_time)
	{
		usleep(100);
		now_time = get_time();
	}
	pthread_mutex_lock(&data->time_mutex);
	data->elapsed_time = (now_time - data->start_time);
	pthread_mutex_unlock(&data->time_mutex);
}
