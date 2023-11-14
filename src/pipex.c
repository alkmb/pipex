/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:01:54 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 08:32:26 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**all_cmd;

	all_cmd = ft_split(cmd, ' ');
	path = get_path(cmd, envp);
	if (execve(path, all_cmd, envp) == -1)
	{
		ft_putstr_fd ("Command not found.\n", 2);
		exit(0);
	}
}

void	child_proces(int *end, char **argv, char **envp)
{
	int	fd1;

	fd1 = open (argv[1], O_RDONLY);
	dup2 (fd1, 0);
	dup2 (end[1], 1);
	close (end[0]);
	close (end[1]);
	exec_cmd (argv[2], envp);
	perror ("Error");
}

void	parent_proces(int *end, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd2, 1);
	dup2(end[0], 0);
	close(end[0]);
	close(end[1]);
	exec_cmd(argv[3], envp);
	perror("Error");
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd ("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit (0);
	}
	if (pipe(end) == -1)
		exit (-1);
	pid = fork();
	if (pid == 0)
		child_proces (end, argv, envp);
	else
	{
		wait (NULL);
		parent_proces (end, argv, envp);
	}
	return (0);
}
