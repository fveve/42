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
# include <readline/history.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include "pipex.h"

/*--------SRCS/BUILTINS/PWD------*/
int		pwd_cmd(void);
int		cd_cmd(t_mini *mini, char *cmd);
void    export_cmd(t_mini *mini ,char *cmd);
void 	ls_cmd(char *cmd);
void	env_cmd(char **env);
void    unset_cmd(t_mini *mini, char *cmd);
void 	echo_cmd(char *cmd);
void    dollar_cmd(t_mini *mini, t_cmd *cmd);

/*--------SRCS/ENV/EXPORT_UTILS---*/
char     **add_env_variable(t_mini *mini, char *new_env_var);

/*-------SRCS/EXEC/EXEC---------*/
void    exec(t_data *data);

/*--------SRCS/EXEC/EXIT--------*/
int exit_manager(t_data *data);

/*-------SRCS/PARSING--------*/
void	init_data(t_data *data, char **env);
void	init_mini(t_mini *mini, char **env);
void	init_mini2(t_mini *mini, char **env);
void	init_cmd(t_cmd *cmd, char *input_str);

/*------- SRCS/MAIN/MANAGER------*/
void loop(t_data *data);

/*-------SRCS/MAIN/SIGNAL-------*/
void handle_signal(int sig);

/*--------HANDLE PIPE/REDIRECTION/APPEND*/
void	pipex(t_data data);

/*--------SRCS/TOOLS/FREE_UTILS---*/
void	free_tab(char **tab);
void 	free_cmd(t_cmd *cmd);
char	**free_export_unset(char *env_one_line);
void	free_mini(t_mini *mini);

/*--------SRCS/TOOLS/FT_SPLIT----*/
char	**ft_split(char const *s, char *c);

/*--------srcs/TOOLS/LIBUTILS---*/
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		ft_strlen(const char *str);
int		ft_strlen2(char **tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);

/*TO REMOVE*/
void	it_works(char **tab);

#endif