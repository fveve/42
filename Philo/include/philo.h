#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//						  __________			          //
//----------------------/*Structures*\-------------------//
typedef	struct s_philo
{
	int	*args;
}	t_philo;
//---------------------\*__________*/-------------------//

//						  __________					 //
//----------------------/*Functions*\-------------------//
int		check_args(t_philo *philo, int argc, char **input);
//tools
char	**ft_split(char const *s, char c);
int		ft_atoi( char *nptr);
int		ft_strlen(char *str);
//parsing
int	parse_numbers(t_philo *philo, int argc, char **argv);
//debug
void	printf_int_tab(int *tab);
//---------------------\*__________*/-------------------//
#endif