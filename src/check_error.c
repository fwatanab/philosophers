/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:21:34 by fwatanab          #+#    #+#             */
/*   Updated: 2024/01/24 19:24:04 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	check_args_data(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isalpha((int)argv[i++]) == 1)
			return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_args_data(argv[i]) == 1)
		{
			printf("Error: No alphabets in arguments.\n");
			return (1);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			printf("Error: Negative value provided.\n");
			return (1);
		}
		i++;
	}
	return (0);
}