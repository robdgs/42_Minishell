/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_comands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:27:09 by tfalchi           #+#    #+#             */
/*   Updated: 2024/08/28 17:27:53 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void env_comands(char *input)
{
	if (ft_strcmp(input, "env") == 0)
		printf("env\n");
	else if (ft_strcmp(input, "export") == 0)
		printf("export\n");
	else if (ft_strcmp(input, "unset") == 0)
		printf("unset\n");
}