/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:31:43 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/07 11:48:21 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data		data;
	
	(void)argc;
	(void)argv;
	data = initialize_data(env);
	while(1)
	{
		data.input = readline("Minishell> "); //(ex data.original_input)
		//data.input = ft_strdup(data.original_input); (ex data.input)
		if (data.input)
            add_history(data.input); ////to do: da addare tutto assieme se le "" rompono la linea
		data = parsing(data);
		if(ft_strcmp("exit", data.input) == 0)
		{
			rl_clear_history();
			free_all(&data);
			break;
		}
		else
		{
			execute_command(&data);
			free_input(&data);
		}
	}	
	return (0);
}
