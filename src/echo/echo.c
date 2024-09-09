/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:19:38 by rd-agost          #+#    #+#             */
/*   Updated: 2024/09/09 11:19:45 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void builtin_echo(t_data *data)
{
    int i = 0;
    int newline = 1;

	if(data->args == NULL)
		return;
    if (data->args[i] && strcmp(&data->args[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    while (data->args[i])
    {
        printf("%c", data->args[i]);
        i++;
    }
    if (newline)
        printf("\n");
}