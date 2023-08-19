/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:44:33 by fwatanab          #+#    #+#             */
/*   Updated: 2023/08/09 20:27:10 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <pthread.h>

# define TRUE 0
# define FALSE 1

typedef struct s_philo
{
	pthread_t	p_id;
	int			id;
	int			l_fork;
	int			r_fork;
	int			eat_count;
}	t_philo;

typedef struct s_control
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				fin;
	t_philo			*philo;
	pthread_mutex_t	mutex;
	int				death;
	int				num;
}	t_control;

int		error(void);
void	start_philo(t_control *data);
void	*funk(void *data);

# endif
