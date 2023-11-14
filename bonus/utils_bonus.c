/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:43:06 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 08:31:57 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_envp(char *n_envp, char **envp)
{
	char	*envp_path;
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
			free(envp_path);
			return (envp[i] + j + 1);
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
	free(all_path);
	free(all_cmd);
	return (cmd);
}

void	handle_input_redirection(int in, char **argv)
{
	int	fd;

	if (in)
	{
		fd = open(argv[1], O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
}

void	handle_output_redirection(int *end, int out, char **argv)
{
	int	fd;

	if (out)
	{
		dup2(end[1], 1);
		close(end[1]);
	}
	else
	{
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, 1);
		close(fd);
		dup2(end[0], 0);
		close(end[0]);
	}
}

void	exec_pipe(int *end, char **argv, int in_out, char **envp)
{
	int		in;
	int		out;
	char	**all_cmd;

	in = in_out & 1;
	out = in_out >> 1;
	all_cmd = ft_split(argv[2], ' ');
	handle_input_redirection(in, argv);
	handle_output_redirection(end, out, argv);
	exec_cmd_bns(all_cmd, envp);
}
