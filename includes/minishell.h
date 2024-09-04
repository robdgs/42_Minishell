/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:01:24 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/04 15:55:12 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	char	**env;				
	char	*input;				
	char	*original_input;	
	char	*command;			//command to execute
	char	*args;				//arguments of the command
	int 	flag;				
}			t_data;


void	print_matrix(char **matrix);
char	**matrix_dup(char **matrix);
void	print_name();
char	*read_input();
void	execute_command(t_data data);
void	free_all();
void	free_input(t_data data);
void	free_env(t_data data);
void	print_name();
int		ft_strcmp(const char *s1, const char *s2);
int 	pwd();
t_data	initialize_data(char **env);
t_data	parsing(t_data data);
t_data	del_extra_spaces(t_data data);
void	export(t_data data);
void	print_export(t_data data);
t_data	split_input(t_data data);
char	**realloc_env(t_data data);

#endif
