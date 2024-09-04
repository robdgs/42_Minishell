/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:11:12 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/04 12:20:26 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_export(t_data data)
{
	int i;

	i = 0;
	while (data.env[i] != NULL)
	{
		ft_printf("declare -x %s\n", data.env[i]);
		i++;
	}
}

char	**realloc_env(t_data data)
{
	int		i;
	char	**new_env;

	i = 0;
	while (data.env[i] != NULL)
		i++;
	new_env = calloc(sizeof(char *), i + 2);
	i = 0;
	while (data.env[i] != NULL)
	{
		new_env[i] = ft_strdup(data.env[i]);
		i++;
	}
	free_env(data);
	return (new_env);
}
