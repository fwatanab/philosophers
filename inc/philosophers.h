/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:44:33 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/07 19:19:07 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/inc/libft.h"
# include <pthread.h>

typedef struct s_philo
{
	int	data;
	int	number;
	int	die;
	int	eat;
	int	sleep;
	int	fin;
}	t_philo;

int	error(void);

# endif
