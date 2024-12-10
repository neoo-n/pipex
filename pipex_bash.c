/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:57:51 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/10 16:59:38 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_bash(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
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

void	parent_process_bash(t_fdpath fdpath, char *arg, char **env, int *fdpipe)
{
	char	**cmd;

	cmd = NULL;
	if (close(fdpipe[1]) == -1)
		error_managefree(fdpath, NULL, "Error close pipe 1 (parent)");
	if (dup2(fdpipe[0], STDIN_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdin (parent)");
	if (dup2(fdpath.fd2, STDOUT_FILENO) == -1)
		error_managefree(fdpath, NULL, "Error dup2 stdout (parent)");
	if (!ft_strncmp(fdpath.path2, "./", 2))
		
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