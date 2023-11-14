/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:26:01 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 08:37:44 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

void	exec_cmd_bns(char **cmd, char **envp);
void	exec_pipe(int *end, char **argv, int in_out, char **envp);
void	handle_input_redirection(int in, char **argv);
void	handle_output_redirection(int *end, int out, char **argv);
void	child_proces(int *end, char **argv, char **envp);
void	parent_proces(int *end, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
char	*get_envp(char *name, char **envp);

#endif
