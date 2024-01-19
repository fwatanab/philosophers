/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:38 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/19 22:26:06 by fwatanab         ###   ########.fr       */
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
//	pthread_mutex_lock(&philo->control->eat_loop);
	if (philo->control->p_death == LIFE && !philo->control->eat_fin)
	{
		pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
		printf("%lld %d has taken a fork\n", \
				philo->control->elapsed_time, philo->id);
		pthread_mutex_lock(&philo->control->fork[philo->r_fork]);
		printf("%lld %d has taken a fork\n", \
				philo->control->elapsed_time, philo->id);
		pthread_mutex_lock(&philo->control->surveil_mutex);
		if (surveillance(philo->control, philo) == 1)
		{
			pthread_mutex_unlock(&philo->control->surveil_mutex);
			pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
			pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
			pthread_mutex_unlock(&philo->control->eat_loop);
			return ;
		}
		pthread_mutex_unlock(&philo->control->surveil_mutex);
		printf("%lld %d is eating\n", \
				philo->control->elapsed_time, philo->id);
		philo->eat_count += 1;
		check_eat_count(philo->control);
		if (philo->control->eat_fin)
		{
			pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
			pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
			pthread_mutex_unlock(&philo->control->eat_loop);
			return ;
		}
		count_time(philo->control, philo->control->eat);
		philo->eat_time = philo->control->elapsed_time;
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
	}
//	pthread_mutex_unlock(&philo->control->eat_loop);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->control->p_death == LIFE && !philo->control->eat_fin)
	{
		printf("%lld %d is sleeping\n", \
				philo->control->elapsed_time, philo->id);
		count_time(philo->control, philo->control->sleep);
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->control->p_death == LIFE && !philo->control->eat_fin)
	{
		printf("%lld %d is thinking\n", \
				philo->control->elapsed_time, philo->id);
	}
}
