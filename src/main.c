/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/29 20:03:58 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_control	*data;

	if (argc < 5 || 6 < argc)
		return (error());
	data = (t_control *)malloc(sizeof(t_control));
	if (!data)
		return (1);
	input_args(argc, argv, data);
	if (!data->philo)
		return (1);
	pthread_mutex_init(data->fork, NULL);
	start_philo(data);
	pthread_mutex_destroy(data->fork);
	free(data->philo);
	free(data->fork);
	free(data);
	return (0);
}
