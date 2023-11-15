/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:46:46 by akambou           #+#    #+#             */
/*   Updated: 2023/11/15 17:10:28 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_split(char **split)
{
	char	**original_split;

	original_split = split;
	while (*split != NULL)
	{
		free(*split);
		split++;
	}
	free(original_split);
}

void	chose_command(int *fd_old, int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	int		fd_new[2];

	i = 2;
	while (i < argc - 1)
	{
		if (pipe(fd_new) == -1)
		{
			perror("Error creating pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0)
			execute_mid_command(fd_old, fd_new, argv[i], envp);
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

void	exec_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**all_cmd;
	char	**original_cmd;

	all_cmd = ft_split(cmd, ' ');
	original_cmd = all_cmd;
	path = get_path(cmd, envp);
	if (execve(path, all_cmd, envp) == -1)
	{
		ft_putstr_fd ("Command not found.\n", 2);
		exit(0);
	}
	free_split(original_cmd);
	free(path);
}

char	*get_envp(char *n_envp, char **envp)
{
	char	*envp_path;
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		envp_path = ft_substr(envp[i], 0, j);
		if (ft_strncmp(envp_path, n_envp, j) == 0)
		{
			result = envp[i] + j + 1;
			free(envp_path);
			return (result);
		}
		free(envp_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*cmd_pth;
	char	*path_part;
	char	**all_path;
	char	**all_cmd;

	i = 0;
	all_path = ft_split(get_envp("PATH", envp), ':');
	all_cmd = ft_split(cmd, ' ');
	if (all_path == NULL || all_cmd == NULL)
		return (NULL);
	while (all_path[i])
	{
		path_part = ft_strjoin(all_path[i], "/");
		cmd_pth = ft_strjoin(path_part, all_cmd[0]);
		free(path_part);
		if (access(cmd_pth, F_OK | X_OK) == 0)
			return (cmd_pth);
		free(cmd_pth);
		i++;
	}
	free_split(all_path);
	free_split(all_cmd);
	return (cmd);
}
