/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:00 by akambou           #+#    #+#             */
/*   Updated: 2023/11/23 01:08:20 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define READ_END 0
# define WRITE_END 1
# define FILE1 1
# define CMD1 2
# define CMD2 3
# define FILE2 4

# include "../../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

void	execute_first_command(int *fd, char **argv, char **envp);
void	execute_second_command(int *fd, char **argv, char **envp);
void	execute_mid_command(int *fd_old, int *fd_new, char *argv, char **envp);
void	execute_last_command(int *fd_old, int argc, char **argv, char **envp);
void	chose_command(int *fd_old, int argc, char **argv, char **envp);
void	exec_cmd(char *cmd, char **envp);
void	free_array(char **array);
char	*get_path(char *cmd, char **envp);
char	*get_envp(char *name, char **envp);

#endif
