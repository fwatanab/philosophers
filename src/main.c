/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/09 20:50:00 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"


t_philo	*input_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->number = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->fin = ft_atoi(argv[5]);
	return (philo);
}

void	*print(void *data)
{
	t_thread	*thread;
	int			i;

	i = 0;
	thread = (t_thread *)data;
	while (i < 100000)
	{
		pthread_mutex_lock(&(thread->mutex));
		thread->num++;
		i++;
		pthread_mutex_unlock(&(thread->mutex));
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	pthread_t		pth_id;
	pthread_t		pth_id2;
	t_philo			*philo;
	t_thread		thread;

	if (argc < 5 || 6 < argc)
		return (error());
	philo = input_philo(argc, argv);
	if (!philo)
		return (error());
	thread.num = 0;
	pthread_mutex_init(&(thread.mutex), NULL);
	pthread_create(&pth_id, NULL, print, &thread);
	pthread_create(&pth_id2, NULL, print, &thread);
	pthread_join(pth_id, NULL);
	pthread_join(pth_id2, NULL);
	printf("main: %d\n", thread.num);
	pthread_mutex_destroy(&(thread.mutex));
	free(philo);
	return (0);
}
