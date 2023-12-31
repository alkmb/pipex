/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:26:01 by akambou           #+#    #+#             */
/*   Updated: 2023/11/15 08:54:49 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1
# define FILE1 1
# define CMD1 2
# define CMD2 3
# define FILE2 4

# include "../libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

void	execute_first_command(int *fd, char **argv, char **envp);
void	execute_second_command(int *fd, char **argv, char **envp);
void	exec_cmd(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);
char	*get_envp(char *name, char **envp);

#endif
