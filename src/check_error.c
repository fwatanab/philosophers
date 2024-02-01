/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:21:34 by fwatanab          #+#    #+#             */
/*   Updated: 2024/02/01 21:07:46 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	check_args_data(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isnumber((int)argv[i++]) == 0)
			return (1);
	}
	return (0);
}

static int	check_zero(char **argv)
{
	int	i;

	i = 1;
	if (argv[i][0] == '0')
	{
		printf("Error: Number of philosophers cannot be zero.\n");
		return (1);
	}
	i++;
	while (argv[i])
	{
		if (argv[i][0] == '0')
		{
			printf("Error: Zero cannot be specified.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]))
		{
			printf("Error: Invalid or empty argument provided.\n");
			return (1);
		}
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
	if (check_zero(argv) == 1)
		return (1);
	return (0);
}
