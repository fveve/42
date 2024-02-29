/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:01:33 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/21 14:01:33 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
#include <fcntl.h>
# include "pipex.h"

/*--------SRCS/BUILTINS/PWD------*/
int		pwd_cmd(void);
int		cd_cmd(t_mini *mini, t_cmd *cmd);
void    export_cmd(t_mini *mini, t_cmd *cmd);
void	ls_cmd(t_cmd *cmd);


/*-------SRCS/EXEC/EXEC---------*/
void    exec(t_mini *mini, t_cmd *cmd);

/*-------SRCS/MAIN/MAIN---------*/

/*------- SRCS/MAIN/MANAGER------*/
void loop(t_mini *mini);

/*-------SRCS/MAIN/SIGNAL-------*/
void handle_signal(int sig);
/*--------HANDLE PIPE/REDIRECTION/APPEND*/
/*--------SRCS/TOOLS/FREE_UTILS---*/
void	free_tab(char **tab);
void	free_cmd(t_cmd *cmd);
/*--------SRCS/TOOLS/FT_SPLIT----*/
char	**ft_split(char const *s, char c);
/*--------srcs/TOOLS/LIBUTILS---*/
int	ft_strncmp(const char *s1, const char *s2, size_t size);
int	ft_strlen(const char *str);
int	ft_strlen2(char **tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);


/*TO REMOVE*/
void	it_works(char **tab);



#endif