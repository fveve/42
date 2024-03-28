/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:10:20 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:44:15 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "minishell.h"


//Structure-------------------------------------------------
typedef struct s_mini
{
    char	**env;
	char	**export_env;
	char	*cwd;//current working directory
}               t_mini;

typedef struct s_cmd
{
	char	**cmds;
	char	*input_str;
	int		pipes;
} t_cmd;

typedef struct s_data
{
	int input;
	int output;
	t_cmd	cmd;
	t_mini	mini;
}	t_data;

//Functions-------------------------------------------------
int 	is_tiret(char *s);
int		is_file(char *s);
int		is_path(char *s);
char	*ft_substr(char const *s, int start, int len);
char	**extract_args(char **argv, int x);
void 	ft_check_args(int argc, char **argv, char **env, t_data *data);
void 	exec_child(t_data data, int x);
void	verify_path(char *path);
void	free_tab(char **tab);
#endif