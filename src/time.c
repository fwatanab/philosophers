#include "../inc/philosophers.h"

void	count_time(t_control *data)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	printf("%ldms\n", tv.tv_usec);
}
