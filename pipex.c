/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:46:05 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/03 11:40:27 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	forking(int fd1, int fd2, char *path1, char path2)
{
	pid_t	pid;
	pid = fork();
	if (pid == -1)
	{
		free(path1);
		free(path2);
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		wait()
}

void	ft_pipex(int fd1, int fd2, char **argv, char **env)
{
	char	*path1;
	char	*path2;

	path1 = accessing_path(argv[2], env);	
	if (!path1)
	{
		perror("No such command (1)");
		exit(EXIT_FAILURE);
	}
	path2 = accessing_path(argv[3], env);	
	if (!path2)
	{
		free(path1);
		perror("No such command (2)");
		exit(EXIT_FAILURE);
	}
	forking(fd1, fd2, path1, path2);
	free(path1);
	free(path2);
}
