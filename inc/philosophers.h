/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:22:10 by fwatanab          #+#    #+#             */
/*   Updated: 2023/09/02 12:55:07 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define LIFE 0
# define DEATH 1

# define EAT 0
# define SLEEP 1

typedef struct s_control t_control;

typedef struct s_philo
{
	pthread_t		p_id;
	int				id;
	int				l_fork;
	int				r_fork;
	t_control		*control;
	int				eat_count;
}	t_philo;

struct s_control
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				max_eat;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*bed;
	long long		elapsed_time;
	int				p_death;
};

void			input_args(int argc, char **argv, t_control *data);
int				error(void);
void			start_philo(t_control *data);
void			one_philo(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
long long		get_time(void);
void			count_time(t_control *data, int ms_time);
long long		timestamp(struct timeval tv);
void			print_log(struct timeval tv, int p_nbr, char *str);

# endif
