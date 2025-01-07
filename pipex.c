/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:46:05 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 11:57:36 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
{
	char	**cmd;

	if (close(fdpipe[0]) == -1)
		error_managefree(fdpath, NULL, "Error close pipe 0 (child)");
	if (dup2(fdpath.fd1, STDIN_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdin (child)");
	if (dup2(fdpipe[1], STDOUT_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdout (child)");
	cmd = ft_splitpipex(arg, ' ');
	if (!cmd || !cmd[0])
		error_managefree(fdpath, NULL, "Error splitpipex (child)");
	cmd = ft_strtrimpipex(cmd);
	if (!cmd || !cmd[0])
		error_managefree(fdpath, NULL, "Error trimpipex (child)");
	if (execve(fdpath.path1, cmd, env) == -1)
		error_managefree(fdpath, cmd, "Error execve (child)");
	else
		freesplit(cmd);
}

static void	parent_process(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
{
	char	**cmd;

	cmd = NULL;
	if (close(fdpipe[1]) == -1)
		error_managefree(fdpath, NULL, "Error close pipe 1 (parent)");
	if (dup2(fdpipe[0], STDIN_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdin (parent)");
	if (dup2(fdpath.fd2, STDOUT_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdout (parent)");
	cmd = ft_splitpipex(arg, ' ');
	if (!cmd || !cmd[0])
		error_managefree(fdpath, NULL, "Error splitpipex (parent)");
	cmd = ft_strtrimpipex(cmd);
	if (!cmd || !cmd[0])
		error_managefree(fdpath, NULL, "Error trimpipex (parent)");
	if (execve(fdpath.path2, cmd, env) == -1)
		error_managefree(fdpath, cmd, "Error execve (parent)");
	else
		freesplit(cmd);
}

static void	forking(t_fdpath fdpath, char **argv, char **env)
{
	int		fdpipe[2];
	pid_t	pid;

	if (pipe(fdpipe) == -1)
		error_managefree(fdpath, NULL, "Error with the pipe");
	pid = fork();
	if (pid == -1)
		error_managefree(fdpath, NULL, "Error fork");
	else if (pid == 0)
		child_process(fdpath, argv[2], env, fdpipe);
	else
	{
		if (wait(NULL) == -1)
			error_managefree(fdpath, NULL, "Error wait (forking)");
		parent_process(fdpath, argv[3], env, fdpipe);
	}
}

static char	*cpypath(char *path, char *arg, char **env)
{
	if (!ft_strncmp(arg, "./", 2))
		path = ft_strcpypipex(path, arg);
	else
		path = accessing_path(arg, env);
	return (path);
}

void	ft_pipex(t_fdpath fdpath, char **argv, char **env)
{
	fdpath.path1 = cpypath(fdpath.path1, argv[2], env);
	if (!fdpath.path1)
	{
		if(close(fdpath.fd1) == -1)
			error_managefree(fdpath, NULL, "Error close fd1 (path1 ft_pipex)");
		if (close(fdpath.fd2) == -1)
			error_managefree(fdpath, NULL, "Error close fd2 (path1 ft_pipex)");
		write(2, "No such command (1)", 19);
		exit(EXIT_FAILURE);
	}
	fdpath.path2 = cpypath(fdpath.path2, argv[3], env);
	if (!fdpath.path2)
	{
		if(close(fdpath.fd1) == -1)
			error_managefree(fdpath, NULL, "Error close fd1 (path2 ft_pipex)");
		if (close(fdpath.fd2) == -1)
			error_managefree(fdpath, NULL, "Error close fd2 (path2 ft_pipex)");
		write(2, "No such command (2)", 19);
		free(fdpath.path1);
		exit(EXIT_FAILURE);
	}
	forking(fdpath, argv, env);
	free(fdpath.path1);
	free(fdpath.path2);
}
