/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:34:48 by akambou           #+#    #+#             */
/*   Updated: 2023/11/09 23:23:36 by akambou          ###   ########.fr       */
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
