/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:39:48 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/06 16:39:54 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command(t_data *data)
{
	if (ft_strcmp("echo", data->command) == 0)
		printf("echo\n");
	else if (ft_strcmp("cd", data->command) == 0)
		printf("cd\n");
	else if(ft_strcmp("pwd", data->command) == 0)
		pwd();
	else if (ft_strcmp("export", data->command) == 0)
		export(data);
	else if (ft_strcmp("unset", data->command) == 0)
		printf("unset\n");
	/* else if (ft_strcmp("env_matrix", data->command) == 0)
		env_matrix(); */
	else if (ft_strcmp("env", data->command) == 0)
		print_matrix(data->env);
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
