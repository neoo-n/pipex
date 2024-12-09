/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/06 14:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_fdpath	fdpath;
//	int	fd[2];

	if (argc != 5 || !env)
	{
		write(2, "Error : not enough arguments\n", 30);
		return (1);
	}
	fdpath.fd1 = open(argv[1], O_RDONLY);
	if (fdpath.fd1 == -1)
		perror("Error opening files");
/*	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		perror("Error opening files");*/
	fdpath.fd2 = open(argv[4], O_WRONLY | O_CREAT, 0744);
	if (fdpath.fd2 == -1)
	{
		close(fdpath.fd1);
		perror("Error opening/creating file");
	}
/*	fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0744);
	if (fd[1] == -1)
	{
		close(fd[0]);
		perror("Error opening/creating file");
	}
	ft_pipex(fd, argv, env);*/
	fdpath.path1 = NULL;
	fdpath.path2 = NULL;
	ft_pipex(fdpath, argv, env);
	close(fdpath.fd1);
	close(fdpath.fd2);
	return (0);
}
