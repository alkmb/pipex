/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:26:01 by akambou           #+#    #+#             */
/*   Updated: 2023/11/09 23:06:30 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>

void	free_array(char **arr);
void	child_process(int *end, char **argv, char **envp);
void	parent_process(int *end, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
char	*get_envp(char *name, char **envp);

#endif
