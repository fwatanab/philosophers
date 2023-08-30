#include "../inc/philosophers.h"

//void	count_time(t_control *data)
//{
//}
//
int	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("init->%ldms\n", tv.tv_sec);
	printf("init->%dms\n", tv.tv_usec);
	int	tmp;

	tmp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	printf("%d\n", tmp);
	return (tmp);
}
