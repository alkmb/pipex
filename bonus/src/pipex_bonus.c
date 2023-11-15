/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:55 by akambou           #+#    #+#             */
/*   Updated: 2023/11/15 16:41:21 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	execute_first_command(int *fd, char **argv, char **envp)
{
	int	fd1;

	fd1 = open(argv[FILE1], O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	dup2(fd1, 0);
	close(fd1);
	dup2(fd[WRITE_END], 1);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	exec_cmd(argv[CMD1], envp);
	perror("Error executing first command");
	exit(EXIT_FAILURE);
}

void	execute_mid_command(int *fd_old, int *fd_new, int i, \
char **argv, char **envp)
{
	dup2(fd_old[READ_END], 0);
	close(fd_old[READ_END]);
	dup2(fd_new[WRITE_END], 1);
	close(fd_new[WRITE_END]);
	exec_cmd(argv[i], envp);
	perror("Error executing second command");
	exit(EXIT_FAILURE);
}

void	execute_last_command(int *fd_old, int argc, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	dup2(fd2, 1);
	close(fd2);
	dup2(fd_old[READ_END], 0);
	close(fd_old[READ_END]);
	close(fd_old[WRITE_END]);
	exec_cmd(argv[argc - 2], envp);
	perror("Error executing second command");
	exit(EXIT_FAILURE);
}

void	parent_proces(int *fd_old, char **argv, char **envp, int argc)
{
	int		i;
	pid_t	pid;
	int		fd_new[2];

	i = 2;
	if (pipe(fd_old) == -1)
	{
		perror("Error creating pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		execute_first_command(fd_old, argv, envp);
	else
	{
		wait(NULL);
		close(fd_old[WRITE_END]);
		while (i < argc - 1)
		{
			if (pipe(fd_new) == -1)
			{
				perror("Error creating pipe");
				exit(EXIT_FAILURE);
			}

			pid = fork();
			if (pid == 0)
				execute_mid_command(fd_old, fd_new, i, argv, envp);
			else
			{
				wait(NULL);
				close(fd_new[WRITE_END]);
				close(fd_old[READ_END]);
				fd_old[READ_END] = fd_new[READ_END];
				i++;
			}
		}
		execute_last_command(fd_old, argc, argv, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (argc < 5)
	{
		ft_putstr_fd ("Usage: ./pipex file1 cmd1 cmd2 ... file2\n", 2);
		exit(EXIT_FAILURE);
	}
	parent_proces(fd, argv, envp, argc);
}
