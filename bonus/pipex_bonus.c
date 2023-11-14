/* ************************************************************************** */
/*			*/
/*		:::	  ::::::::   */
/*   pipex_bonus.c			  :+:	  :+:	:+:   */
/*			+:+ +:+		 +:+	 */
/*   By: akambou <akambou@student.42.fr>			+#+  +:+	   +#+		*/
/*		+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/14 08:16:33 by akambou		   #+#	#+#			 */
/*   Updated: 2023/11/14 08:23:42 by akambou		  ###   ########.fr	   */
/*			*/
/* ************************************************************************** */

#include "../includes/pipex.h"

void	create_pipe(int *end)
{
	if (pipe(end) == -1)
		exit (-1);
}

pid_t	create_child_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		return (pid);
	else
		return (-1);
}

void	close_pipe(int *end)
{
	close(end[0]);
	close(end[1]);
}

void	wait_for_child_processes(pid_t *pid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;
	int		i;
	int		in_out;

	i = 2;
	pid = malloc(sizeof(pid_t) * (argc - 3));
	while (i < argc - 1)
	{
		create_pipe(end);
		if (create_child_process() == 0)
		{
			in_out = (i == 2) | ((i < argc - 2) << 1);
			exec_pipe(end, argv, in_out, envp);
			exit(0);
		}
		close_pipe(end);
		i++;
	}
	wait_for_child_processes(pid, argc - 3);
}
