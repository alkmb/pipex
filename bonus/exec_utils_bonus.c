/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:10:17 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 11:10:33 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	exec_cmd_bns(char **cmd, char **envp)
{
	char	*path;

	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd ("Command not found.\n", 2);
		exit(0);
	}
}
