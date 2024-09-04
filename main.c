/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:31:43 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/04 17:16:08 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv, char **env)
{
	t_data		data;
	
	(void)argc;
	(void)argv;
	data = initialize_data(env);
	data.flag = 0;
	while(1)
	{
		data.original_input = readline("Minishell> ");
		data.input = ft_strdup(data.original_input);
		if (data.original_input)
            add_history(data.original_input); ////to do: da addare tutto assieme se le "" rompono la linea
		data = parsing(data);
		printf("input:%s\n", data.input);
		printf("command:%s\n", data.command);
		printf("args:%s\n", data.args);
		if(ft_strcmp("exit", data.input) == 0)
		{
			free_all(data);
			rl_clear_history();
			break;
		}
		else
		{
			execute_command(data);
			free_input(&data);
		}
	}	
	return (0);
}
