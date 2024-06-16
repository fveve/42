#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	check_args(&philo.param, argc, argv);
	free(philo.param.args);
}