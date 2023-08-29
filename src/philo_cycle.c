/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:34:38 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/29 17:55:56 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
	printf("%d hold a left fork\n", philo->id);
}

void	philo_eat(t_philo *philo)
{
	if (philo->control->p_death == FALSE)
	{
//		printf("l_fork->%d\tr_fork->%d\n", philo->l_fork, philo->r_fork);
		pthread_mutex_lock(&philo->control->fork[philo->l_fork]);
		printf("%d hold a left fork\n", philo->id);
		pthread_mutex_lock(&philo->control->fork[philo->r_fork]);
		printf("%d hold a right fork\n", philo->id);
		printf("%d eating\n", philo->id);
		pthread_mutex_unlock(&philo->control->fork[philo->l_fork]);
		pthread_mutex_unlock(&philo->control->fork[philo->r_fork]);
	}
}
