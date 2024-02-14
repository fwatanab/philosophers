/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:42 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/14 19:47:57 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->time_mutex);
	if (philo->control->p_death == LIFE)
		printf("%lld %d has taken a fork\n", \
				philo->control->elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->control->time_mutex);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->time_mutex);
	printf("%lld %d is eating\n", \
			philo->control->elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->control->time_mutex);
	check_eat_count(philo->control);
	pthread_mutex_lock(&philo->control->time_mutex);
	if (philo->control->eat_fin)
	{
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->control->time_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->control->time_mutex);
	count_time(philo->control, philo->control->eat);
	philo->eat_count += 1;
	pthread_mutex_lock(&philo->control->time_mutex);
	philo->eat_time = philo->control->elapsed_time;
	pthread_mutex_unlock(&philo->control->time_mutex);
	return (0);
}
