/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:38 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/30 17:27:39 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
	printf("%d has taken a fork\n", philo->id);
}

void	philo_eat(t_philo *philo)
{
	if (philo->control->p_death == FALSE)
	{
		pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
		printf("%lld %d hold a left fork\n",\
				timestamp(philo->tv), philo->id);
		pthread_mutex_lock(&philo->control->fork[philo->r_fork]);
		printf("%lld %d hold a right fork\n",\
				timestamp(philo->tv), philo->id);
		count_time(philo, EAT);
		printf("%lld %d is eating\n",\
				timestamp(philo->tv), philo->id);
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
	}
}

void	philo_sleep(t_philo *philo)
{

	if (philo->control->p_death == FALSE)
	{
		printf("%lld %d is sleeping\n",\
				timestamp(philo->tv), philo->id);
	}
}

void	philo_think(t_philo *philo)
{

	if (philo->control->p_death == FALSE)
		printf("%lld %d is thinking\n",\
				timestamp(philo->tv), philo->id);
}
