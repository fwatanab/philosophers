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
				philo->control->elapsed_time, philo->id);
		pthread_mutex_lock(&philo->control->fork[philo->r_fork]);
		printf("%lld %d hold a right fork\n",\
				philo->control->elapsed_time, philo->id);
		eat_time(philo->;
		printf("%lld %d is eating\n",\
				philo->control->elapsed_time, philo->id);
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
	}
}

void	philo_sleep(t_philo *philo)
{

	if (philo->control->p_death == FALSE)
	{
		printf("%lld %d is sleeping\n",\
				philo->control->elapsed_time, philo->id);
	}
}

void	philo_think(t_philo *philo)
{

	if (philo->control->p_death == FALSE)
		printf("%lld %d is thinking\n",\
				philo->control->elapsed_time, philo->id);
}
