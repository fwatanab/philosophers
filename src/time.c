/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:30:44 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/11 13:37:21 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	get_time()
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000LL + now_time.tv_usec / 1000LL);
}

//void	count_time(t_control *data, int ms_time)
//{
//	long long	start_time;
//	long long	time;
//
//	time = 0;
//	start_time = get_time();
//	while (time < ms_time)
//	{
//		time = get_time() - start_time;
//		usleep(1000);
//	}
//	pthread_mutex_lock(&data->time_mutex);
//	data->elapsed_time += time;
//	pthread_mutex_unlock(&data->time_mutex);
//}

void	count_time(t_control *data, int ms_time)
{
	long long	now_time;

	usleep(1000 * ms_time);
	now_time = get_time();
//	printf("%lldms\n", now_time - data->start_time);
	pthread_mutex_lock(&data->time_mutex);
	data->elapsed_time += (now_time - data->start_time);
	data->start_time = now_time;
	pthread_mutex_unlock(&data->time_mutex);
}

long long	timestamp(struct timeval tv)
{
	long long	ms_time;

	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}

