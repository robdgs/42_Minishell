/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:39:47 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/07 12:49:57 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_data *data)
{
	int		j;
	int		i;
	char	*substr;

	// for now works only with one variable
	j = 0;
	i = 0;
	if (data->args == NULL) // if there are no arguments, print the environment
	{
		print_export(*data); // funzione da finire
		return ;
	}
	while (data->args[j])
	{
		if (data->args[j] == '_' && data->args[j + 1] == '=')
		{
			while (data->args[j] != '\0' && data->args[j] != ' ')
				j++;
			if (data->args[j] == ' ')
				j++;
		}
		else
		{
			if (ft_isdigit(data->args[j]) || data->args[j] == '=')
			{
				while (data->args[j] != '\0' && data->args[j] != ' ')
					j++;
				i = j - 1;
				while (data->args[i] != '\0' && data->args[i] != ' ' && i != 0)
					i--;
				substr = ft_substr(data->args, i, j - i);
				printf("i = %d, j = %d\n", i, j);
				ft_printf("minishell: export: `%s': not a valid identifier\n", substr);
			}
			else
			{
				while (ft_isalnum(data->args[j]) || data->args[j] == '_')
					j++;
				if (data->args[j] == '=')
				{
					j++;
					while (data->args[j] != '\0' && data->args[j] != ' ')
						j++;
				}
				if (data->args[j] == '\0')
				{
					env_modification(data, j, i);
					return ;
				}
				if (data->args[j] == ' ')
				{
					env_modification(data, j, i);
					j++;
				}
				i = j;
			}
		}
	}
	/* while (data->args[j] != '\0')
		j++; */
	return ;
}

void	env_modification(t_data *data, int j, int x)
{
	char *strcpy;
	int i;

	i = 0;
	strcpy = ft_calloc(sizeof(char), j - x + 1);
	ft_strlcpy(strcpy, &data->args[x], j - x + 1);
	while (data->env[i] != NULL)
	{
		if (ft_strncmp(data->env[i], strcpy, j) == 0)
		// if the variable is already in the environment, update it
		{
			free(data->env[i]);
			data->env[i] = NULL;
			data->env[i] = ft_strdup(strcpy);
			free(strcpy);
			return ;
		}
		i++;
	}
	data->env = realloc_env(*data);
	// if the variable is not in the environment, realloc the environment
	data->env[i] = ft_strdup(strcpy); // and add the variable
	free(strcpy);
	strcpy = NULL;
	return ;
}
