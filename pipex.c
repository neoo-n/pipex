/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:46:05 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/06 14:35:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

static void	child_process(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
{
	char	**cmd;

	close(fdpipe[0]);
	dup2(fdpath.fd1, STDIN_FILENO);
	dup2(fdpipe[1], STDOUT_FILENO);
	cmd = ft_splitpipex(arg, ' ');
	execve(fdpath.path1, cmd, env);
}

static void	parent_process(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
{
	char	**cmd;

	close(fdpipe[1]);
	dup2(fdpipe[0], STDIN_FILENO);
	dup2(fdpath.fd2, STDOUT_FILENO);
	cmd = ft_splitpipex(arg, ' ');
	execve(fdpath.path2, cmd, env);
}

static void	forking(t_fdpath fdpath, char **argv, char **env)
{
	int		fdpipe[2];
	pid_t	pid;

	if (pipe(fdpipe) == -1)
	{
		free(fdpath.path1);
		free(fdpath.path2);
		perror("Error with the pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		free(fdpath.path1);
		free(fdpath.path2);
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_process(fdpath, argv[1], env, fdpipe);
	else
	{
		wait(NULL);
		parent_process(fdpath, argv[2], env, fdpipe);
	}
}

void	ft_pipex(t_fdpath fdpath, char **argv, char **env)
{
	fdpath.path1 = accessing_path(argv[2], env);
	if (!fdpath.path1)
	{
		perror("No such command (1)");
		exit(EXIT_FAILURE);
	}
/*	paths[0] = accessing_path(argv[2], env);	
	if (!paths[0])
	{
		perror("No such command (1)");
		exit(EXIT_FAILURE);
	}*/
	fdpath.path2 = accessing_path(argv[3], env);
	if (!fdpath.path2)
	{
		free(fdpath.path1);
		perror("No such command (1)");
		exit(EXIT_FAILURE);
	}
/*	paths[1] = accessing_path(argv[3], env);	
	if (!paths[1])
	{
		free(paths[0]);
		perror("No such command (2)");
		exit(EXIT_FAILURE);
	}*/
	forking(fdpath, argv, env);
	free(fdpath.path1);
	free(fdpath.path2);
}
