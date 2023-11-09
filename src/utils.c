/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:53:31 by akambou           #+#    #+#             */
/*   Updated: 2023/11/09 12:10:04 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_strdup(envp[i] + 5);
		i++;
	}
	return (path);
}

void	get_env(char **argv, char **envp)
{
	char	*env;
	char	**paths;
	char	**argums;
	char	*my_path;

	argums = ft_split(argv[2], ' ');
	my_path = get_path(envp);
	paths = ft_split(my_path, ':')
	env = ft_strjoin(my_path, argv[2]);
}
