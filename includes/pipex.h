/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:26:01 by akambou           #+#    #+#             */
/*   Updated: 2023/11/09 12:10:21 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

void	child_process(int *fd1, char **cmd1, char **envp);
void	parent_process(int *fd1, char **cmd2, char **envp);
char	*get_path(char **envp);
void	get_env(char **argv, char **envp);


#endif
