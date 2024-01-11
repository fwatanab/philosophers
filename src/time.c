/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:30:44 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/11 15:36:08 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	get_time()
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000LL + now_time.tv_usec / 1000LL);
}

void	count_time(t_control *data, int ms_time)
{
	long long	now_time;

	usleep(1000 * ms_time);
	now_time = get_time();
//	printf("%lldms\n", now_time - data->start_time);
	data->elapsed_time += (now_time - data->start_time);
	data->start_time = now_time;
}

long long	timestamp(struct timeval tv)
{
	long long	ms_time;

	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}

