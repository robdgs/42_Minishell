/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:07:37 by tfalchi           #+#    #+#             */
/*   Updated: 2024/08/28 17:26:21 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(char *input)
{
    char *env_var;
	if (strncmp("echo", input) == 0) 
		input += 4;
	else
	{
		printf("Error: invalid command\n");
		return;
	}
	if (strncmp(input, " $") == 0) 
	{
		env_var = getenv(input + 2);
		
	}
	else
	{
		while (ft_strcmp("echo", input) == 0)
		{
			/* code */
		}
		
		printf("%s\n", input);
	}
}