/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:38 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/25 20:55:23 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
	printf("%d has taken a fork\n", philo->id);
	count_time(philo->control, philo->control->die);
	printf("%lld %d died\n", \
			philo->control->elapsed_time, philo->id);
	philo->control->p_death = DEATH;
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->time_mutex);
	if (philo->control->p_death != LIFE || philo->control->eat_fin)
	{
		pthread_mutex_unlock(&philo->control->time_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->control->time_mutex);
	pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
	take_forks(philo);
	pthread_mutex_lock(&philo->control->fork[philo->r_fork]);
	take_forks(philo);
	pthread_mutex_lock(&philo->control->surveil_mutex);
	if (surveillance(philo->control, philo) == 1)
	{
		pthread_mutex_unlock(&philo->control->surveil_mutex);
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
		return ;
	}
	pthread_mutex_unlock(&philo->control->surveil_mutex);
	if (eating(philo) == 1)
		return ;
	pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->time_mutex);
	if (philo->control->p_death != LIFE || philo->control->eat_fin)
	{
		pthread_mutex_unlock(&philo->control->time_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->control->time_mutex);
	pthread_mutex_lock(&philo->control->time_mutex);
	printf("%lld %d is sleeping\n", \
			philo->control->elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->control->time_mutex);
	count_time(philo->control, philo->control->sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->time_mutex);
	if (philo->control->p_death != LIFE || philo->control->eat_fin)
	{
		pthread_mutex_unlock(&philo->control->time_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->control->time_mutex);
	pthread_mutex_lock(&philo->control->time_mutex);
	printf("%lld %d is thinking\n", \
			philo->control->elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->control->time_mutex);
}
