#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	check_args(&philo, argc, argv);
	free(philo.args);
}