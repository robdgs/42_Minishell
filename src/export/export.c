/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:39:47 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/03 17:49:30 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void export(t_data data) // for now works only with one variable
{
	int		i;
	int		j;
	char	*strcpy;
	
	i = 0;
	j = 0;
	if (data.args == NULL) //if there are no arguments, print the environment
		print_export(data); //funzione da creare
	if (data.args[0] == '_' && data.args[1] == '=') //if the first argument is "_=" return
		return;
	while (ft_isalnum(data.args[j]) == 1 || data.args[j] == '_')//j = name of the variable
		j++;
	strcpy = calloc(sizeof(char), j + 1);
	ft_strlcpy(strcpy, data.args, j); //copy the name of the variable
	while (data.env[i] != NULL)
	{
		if (ft_strncmp(data.env[i], strcpy, j) == 0) //if the variable is already in the environment, update it
		{
			free(data.env[i]);
			data.env[i] = ft_strdup(data.args);
		}
		i++;
	}
	data.env = realloc_env(data); //if the variable is not in the environment, realloc the environment
	data.env[i] = ft_strdup(data.args); //and add the variable
	free(strcpy);
	return;
}
