/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:19:38 by rd-agost          #+#    #+#             */
/*   Updated: 2024/09/09 16:18:01 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtin_echo(t_data *data)
{
    int i = 0;

	if(data->args == NULL)
	{
		printf("\n");
		return;
	}
    if (data->args[i] && strcmp(&data->args[i], "-n") == 0)
        i++;
    while (data->args[i])
    {
		if ((data->args[i] == '\"' || data->args[i] == '\'')
			&& data->args[i + 1] == '\0')
			break;
		else if (data->args[i] == '\"' || data->args[i] == '\'')
			i++;
        else
		{
			printf("%c", data->args[i]);
        	i++;
		}
    }
    printf("\n");
}
