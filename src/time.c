#include "../inc/philosophers.h"

long long	get_time()
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000 + now_time.tv_usec / 1000);
}

void	count_time(t_control *data, int ms_time)
{
	long long	start_time;
	long long	time;

	time = 0;
	start_time = get_time();
	while (time < ms_time)
	{
		time = get_time() - start_time;
		usleep(1000);
	}
	data->elapsed_time += time;
}

long long	timestamp(struct timeval tv)
{
	long long	ms_time;

	ms_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms_time);
}

