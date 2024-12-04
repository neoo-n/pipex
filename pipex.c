/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:46:05 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/04 14:40:23 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(int fd, char *path, char *arg, char **env)
{
	char	**cmd;

	dup2(fd, STDIN_FILENO);

}

static void	parent_process(int fd, char *path, char *arg, char **env)
{
	
}

static void	forking(int *fd, char **paths, char **argv, char **env)
{
	int		fdpipe[2];
	pid_t	pid;

	if (pipe(fdpipe) == -1)
	{
		free(paths[0]);
		free(paths[1]);
		perror("Error with the pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		free(paths[0]);
		free(paths[1]);
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_process(fd[0], paths[0], argv[1], env);
	else
	{
		wait();
		parent_process(fd[1], paths[1], argv[2], env);
	}
}

void	ft_pipex(int *fd, char **argv, char **env)
{
	char	*paths[2];

	paths[0] = accessing_path(argv[2], env);	
	if (!paths[0])
	{
		perror("No such command (1)");
		exit(EXIT_FAILURE);
	}
	paths[1] = accessing_path(argv[3], env);	
	if (!paths[1])
	{
		free(paths[0]);
		perror("No such command (2)");
		exit(EXIT_FAILURE);
	}
	forking(fd, paths, argv, env);
	free(paths[0]);
	free(paths[1]);
}
