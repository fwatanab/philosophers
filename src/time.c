#include "../inc/philosophers.h"

struct timeval	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv);
}

void	count_time(t_philo *philo, int flag)
{
	struct timeval	tv;
	struct timeval	now_time;

	gettimeofday(&tv, NULL);
	if (flag == EAT)
		usleep(philo->control->eat * 1000);
	gettimeofday(&now_time, NULL);
	philo->tv.tv_sec += (now_time.tv_sec - tv.tv_sec);
	philo->tv.tv_usec += (now_time.tv_usec - tv.tv_usec);
//	if (data->tv.tv_usec >= 1000000)
//	{
//		data->tv.tv_sec += 1;
//		data->tv.tv_usec -= 1000000;
//	}
}

long long	timestamp(struct timeval tv)
{
	long long	ms_time;

	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}
