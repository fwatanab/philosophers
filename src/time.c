#include "../inc/philosophers.h"

long long	get_time()
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);

	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	check_time(t_control *data, int flag)
{
	long long	now_time;
	long long	tmp;
	int			time;

	now_time = get_time();
	if (flag == EAT)
		usleep(data->eat * 1000);
//	if (flag == SLEEP)
//		usleep(data->sleep * 1000);
	tmp = get_time();
	time = tmp - now_time;
	data->elapsed_time += time;
	printf("elapsed time->%d\n", data->elapsed_time);
}

long long	timestamp(t_control *data)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return (((now_time.tv_sec - data->tv_sec) * 1000)\
			+ ((now_time.tv_usec - data->tv_usec) / 1000));
}

int	main()
{
	struct timeval	tv;
	long long		elapsed_time;

	gettimeofday(&tv, NULL);
	usleep(15000);
	elapsed_time = timestamp(tv);
	printf("%lld\n", elapsed_time);
	return 0;
}
