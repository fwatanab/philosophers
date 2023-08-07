/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:54:40 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/07 19:19:16 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_philo	input_philo(int argc, char **argv)
{
	t_philo	philo;

	philo.number = ft_atoi(argv[1]);
	philo.die = ft_atoi(argv[2]);
	philo.eat = ft_atoi(argv[3]);
	philo.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo.fin = ft_atoi(argv[5]);
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo philo;

	if (argc < 5 || 6 < argc)
	{
		ft_printf("Error\n");
		return (1);
	}
	philo = input_philo(argc, argv);
	ft_printf("eat %d\n", philo.eat);
	return (0);
}
