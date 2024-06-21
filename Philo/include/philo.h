/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:32:05 by arafa             #+#    #+#             */
/*   Updated: 2024/06/21 15:30:49 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
//						  __________			          //
//----------------------/*Structures*\-------------------//

typedef struct s_param
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		*death;
	int					*is_taken;
	int					is_someone_dead;
	int					index;
	int					nb;
	long				start;
}	t_param;

typedef struct s_philo
{
	int					id;
	int					dying_time;
	int					eat_time;
	int					sleep_time;
	int					nb_of_dining;
	int					has_eaten;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_t			thread;
	t_param				*param;
}	t_philo;
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
void	free_all(t_philo *philo, t_param *param);

//thread
void	init_thread(t_philo *philo, t_param *param);
t_philo	*init_philo(t_philo *philo, t_param *param, char **argv, int argc);
void	end_thread(t_philo *philo, t_param *param);
//usleep
void	ft_sleep(char *msg, int id, int sleeping_time, long start);
//debug
void	printf_int_tab(int *tab);
//---------------------\*__________*/-------------------//
#endif