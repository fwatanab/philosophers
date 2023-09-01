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
