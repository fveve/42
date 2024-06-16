#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//						  __________			          //
//----------------------/*Structures*\-------------------//
typedef	struct s_param
{
	int	*args;
}	t_param;

typedef struct s_philo
{
	int		id;
	int		dead;
	int		right_fork;
	int		left_fork;
	pthread thread;
	t_param	param;
} t_philo;
//---------------------\*__________*/-------------------//

//						  __________					 //
//----------------------/*Functions*\-------------------//
int		check_args(t_param *param, int argc, char **input);
//tools
char	**ft_split(char const *s, char c);
int		ft_atoi( char *nptr);
int		ft_strlen(char *str);
//parsing
int	parse_numbers(t_param *param, int argc, char **argv);
//debug
void	printf_int_tab(int *tab);
//---------------------\*__________*/-------------------//
#endif