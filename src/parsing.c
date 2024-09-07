/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:48:19 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/06 12:31:35 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data		parsing(t_data data)
{
	data = del_extra_spaces(data);
	data = split_input(data);
	return (data);
}

t_data	del_extra_spaces(t_data data)
{
	int		i;
	int		j;
	int		flag1;
	int		flag2;
	char	*strcpy;

	i = 0;
	j = 0;
	flag1 = 0;
	flag2 = 0;
	strcpy = calloc(sizeof(char), ft_strlen(data.input) + 1);
	while (data.input[i] == ' ')
		i++;
	while (data.input[i] != '\0')
	{
		if (data.input[i] == 39 && flag1 % 2 == 0)
			flag2 += 1;
		if (data.input[i] == 34 && flag2 % 2 == 0)
			flag1 += 1;
		while (data.input[i] == ' ' && data.input[i + 1] == ' ' && flag1 % 2 == 0 && flag2 % 2 == 0)
			i++;
		strcpy[j] = data.input[i];
		i++;
		j++;
	}
	data.input = strcpy;
	return (data);
}

t_data	split_input(t_data data)
{
	int		i;
	int		j;
	char	*strcpy;

	i = 0;
	j = 0;
	strcpy = calloc(sizeof(char), ft_strlen(data.input) + 1);
	while (data.input[i] != '\0')
	{
		if (data.input[i] == 39)
		{
			i++;
			while (data.input[i] != 39)
			{
				strcpy[j] = data.input[i];
				i++;
				j++;
			}
			i++;
		}
		if (data.input[i] == 34)
		{
			i++;
			while (data.input[i] != 34)
			{
				strcpy[j] = data.input[i];
				i++;
				j++;
			}
			i++;
		}
		if (data.input[i] == ' ')
		{
			strcpy[j] = '\0';
			data.command = ft_strdup(strcpy);
			j = 0;
			i++;
			while (data.input[i] != '\0')
			{
				strcpy[j] = data.input[i];
				i++;
				j++;
			}
			strcpy[j] = '\0';
			data.args = ft_strdup(strcpy);
			break;
		}
		strcpy[j] = data.input[i];
		i++;
		j++;
	}
	if(data.command == NULL && data.input)
	{
		strcpy[j] = '\0';
		data.command = ft_strdup(strcpy);
	}
	free(strcpy);
	return (data);
}
