/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:39:48 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/03 17:50:42 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command(t_data data)
{
	if (ft_strcmp("echo", data.input) == 0)
		printf("echo\n");
	else if (ft_strcmp("cd", data.input) == 0)
		printf("cd\n");
	else if(ft_strcmp("pwd", data.input) == 0)
		pwd();
	else if (ft_strcmp("export", data.input) == 0)
		export(data);
	else if (ft_strcmp("unset", data.input) == 0)
		printf("unset\n");
	/* else if (ft_strcmp("env_matrix", data.input) == 0)
		env_matrix(); */
	else if (ft_strcmp("env", data.input) == 0)
		print_matrix(data.env);
}

void	print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
