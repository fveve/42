/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 13:32:10 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	go_to_file(char *input_str, int *y, int trigger)
{
	if (!trigger)
	{
		while (input_str[*y] == ' ')
			(*y)--;
		while (input_str[*y] != ' ')
			(*y)--;
		printf("start : %c\n", input_str[*y]);
	}
	else
	{
		while (input_str[*y] == ' ')
			(*y)++;
		while (input_str[*y] != ' ')
			(*y)++;
		printf("start2 : %c", input_str[*y]);
	}
}

void	set_file(t_data *data, char *file, int trigger)
{
	if (!trigger)
		data->input = open(file, O_RDONLY);
	else if (trigger == 1)
		printf("1");
//		handle_here_doc
	else if (trigger == 2)
		data->output = open(file, O_CREAT | O_TRUNC, 0777);
	else if (trigger == 3)
		data->output = open(file, O_APPEND | O_CREAT | O_TRUNC, 0777);
}

void	set_fd(t_data *data, char *input_str)
{
	char	*file;
	int		x;
	int		y;

	x = 0;
	while (input_str[x])
	{
		if (input_str[x] == '>')
		{
			y = x;
			go_to_file(input_str, &y , 1);
			file = ft_substr(input_str, x, y - x);
			if (input_str[x + 1] != '>')
				set_file(data, file, 0);
			else
				set_file(data, file, 1);
			break;
		}
		else if (input_str[x] == '<')
		{
			y = x;
			go_to_file(input_str, &y, 0);
			file = ft_substr(input_str, y, x - y);
			if (input_str[x + 1] != '<')
				set_file(data, file, 2);
			else
				set_file(data, file, 3);
			break;
		}
			x++;
	}
}

void	handle_redirection(t_data *data, char *input_str)
{
	set_fd(data, input_str);
	if (data->input)
		dup2(data->input, 0);
	else if (data->output)
		dup2(data->output, 1);
}