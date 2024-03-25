/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoherna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:19 by leoherna          #+#    #+#             */
/*   Updated: 2024/02/26 17:03:19 by leoherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ls_cmd(char *cmd)
{
    char **command;
    DIR *dir;
    struct dirent *entry;

    command = ft_split(cmd, " ");
    if (!command[1])
    {
        char *cmd_without_arg;
        cmd_without_arg = ft_strjoin(cmd, " .");
        free_tab(command);
        command = ft_split(cmd_without_arg, " ");
		free(cmd_without_arg);
    }

    // Ouvrir le répertoire
    dir = opendir(command[1]);
    

    // Vérifier si l'ouverture du répertoire a réussi
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }
    
    // Parcourir le répertoire
    while ((entry = readdir(dir)) != NULL) {
        printf("%s  ", entry->d_name);
    }
    printf("\n");
    
    // Fermer le répertoire
    closedir(dir);
	free_tab(command);
}

