/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/09/02 13:08:11 by fwatanab         ###   ########.fr       */
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
	start_philo(data);
	free(data->philo);
	free(data->fork);
	free(data->bed);
	free(data);
	return (0);
}
