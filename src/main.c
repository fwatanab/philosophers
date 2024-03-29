/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/24 19:23:25 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_control	*data;

	if (argc < 5 || 6 < argc)
	{
		printf("Error: ncorrect number of arguments.\n");
		return (1);
	}
	if (check_args(argc, argv) == 1)
		return (1);
	data = (t_control *)malloc(sizeof(t_control));
	if (!data)
		return (1);
	input_args(argc, argv, data);
	if (!data->philo)
		return (1);
	start_philo(data);
	free(data->philo);
	free(data->fork);
	free(data);
	return (0);
}
