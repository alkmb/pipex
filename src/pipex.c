/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:53:29 by akambou           #+#    #+#             */
/*   Updated: 2023/11/09 11:46:27 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_proces(int fd1, char **cmd1, char **envp)
{
	fd1 = open(fd1, O_RDONLY);
	dup2(fd1, 0);
	dup2(fd1, 1);
	close(fd1);
	execve(cmd1[0], cmd1, NULL);
}

void	parent_proces(int fd2, char **cmd2, char **envp)
{
	fd2 = open(fd2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd2, 1);
	dup2(fd2, 0);
	close(fd2);
	execve(cmd1[0], cmd2, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	if (argc != 5)
	{
		ft_putstr_fd("Error: need more arguments.\n", 2);
		return (1);
	}
	if (!pid)
		child_proces(end[1], argv[2], envp);
	else
		parent_proces(end[0], argv[3], envp);
}
