/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:05:16 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/04 15:13:32 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_data data)
{
	free_input(data);
	free_env(data);
}

void	free_input(t_data data)
{
	if (data.input) {
		printf("Freeing input: %s\n", data.input);
		free(data.input);
		data.input = NULL;
	}
	if (data.command) {
		printf("Freeing command: %s\n", data.command);
		free(data.command);
		data.command = NULL;
	}
	if (data.args) {
		printf("Freeing args: %s\n", data.args);
		free(data.args);
		data.args = NULL;
	}
	if (data.original_input) {
		printf("Freeing original_input: %s\n", data.original_input);
		free(data.original_input);
		data.original_input = NULL;
	}
}

void	free_env(t_data data)
{
	int i;

	i = 0;
	if (data.env == NULL)
		return;
	while (data.env[i] != NULL)
	{
		free(data.env[i]);
		data.env[i] = NULL;
		i++;
	}
	free(data.env);
	data.env = NULL;
}