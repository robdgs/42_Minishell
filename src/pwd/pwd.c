/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:08:51 by tfalchi           #+#    #+#             */
/*   Updated: 2024/08/27 12:31:26 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pwd()
{
	char *directory = getcwd(NULL, 0);
	if (directory)
	{
		printf("%s\n", directory);
		return (0);
	}
	else
	{
		printf("Error: could not get current directory\n");
		return (1);
	}
}