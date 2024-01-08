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

# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

//Structure------------------------------------------------

typedef struct s_cmd
{
	char *path;
	char **args;
} t_cmd;

//Functions------------------------------------------------
int 	ft_strlen(const char *s);
int 	ft_strlen_tab(char **s);
int		is_file(char *s);
int 	is_tiret(char *s);
char	*ft_substr(char const *s, int start, int len);
char	**extract_args(char **argv, int x);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
void 	ft_check_args(int argc, char **argv);
void	free_tab(char **tab);
void	ft_check_pipe(void);
void	ft_exec_cmd(char **tab, char **envp);

#endif