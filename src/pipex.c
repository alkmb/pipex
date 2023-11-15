/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:05 by akambou           #+#    #+#             */
/*   Updated: 2023/11/15 09:23:06 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex.h"

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

void	execute_second_command(int *fd, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[FILE2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	dup2(fd2, 1);
	close(fd2);

	dup2(fd[READ_END], 0);
	close(fd[READ_END]);
	close(fd[WRITE_END]);

	exec_cmd(argv[CMD2], envp);
	perror("Error executing second command");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd ("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creating pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		execute_first_command(fd, argv, envp);
	else
	{
		wait(NULL);
		execute_second_command(fd, argv, envp);
	}
}
