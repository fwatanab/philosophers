/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:29:16 by fwatanab          #+#    #+#             */
/*   Updated: 2023/12/17 04:29:18 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	error(void)
{
	ft_printf("Error\n");
	return (1);
}

void	print_log(struct timeval tv, int p_nbr, char *str)
{
	long long	ms_time;

	ms_time = timestamp(tv);
	printf("%lld %d %s\n", ms_time, p_nbr, str);
}
