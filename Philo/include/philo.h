#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//						  __________			          //
//----------------------/*Structures*\-------------------//

typedef struct s_param
{
	pthread_mutex_t	*fork;
	int				nb;
}	t_param;

typedef struct s_philo
{
	int					id;
	int					dying_time;
	int					eat_time;
	int					sleep_time;
	int					nb_of_dining;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		left_fork;
	pthread_t			thread;
	t_param				*param;
} t_philo;
//---------------------\*__________*/-------------------//

//						  __________					 //
//----------------------/*Functions*\-------------------//
int		check_args(int argc, char **input);
//exit
void	exit_manager(char *msg, t_philo *philo);
//tools
int		ft_atoi( char *nptr);
int		ft_strlen(char *str);
void	printf_int_tab(int *tab);
char	*ft_strdup(char *input);
int		is_number(char *input);

//parsing
int		parse_numbers(int argc, char **argv);
int		init_thread(t_philo *philo, char **argv, int argc);
//debug
void	printf_int_tab(int *tab);
//---------------------\*__________*/-------------------//
#endif