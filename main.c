/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/09 11:27:05 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_fdpath	fdpath;

	if (argc != 5 || !env)
	{
		write(2, "Error : not enough arguments\n", 30);
		return (1);
	}
	fdpath.fd1 = open(argv[1], O_RDONLY);
	if (fdpath.fd1 == -1)
		return (perror("Error opening files"), 1);
	fdpath.fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fdpath.fd2 == -1)
	{
		close(fdpath.fd1);
		perror("Error opening/creating file");
		return (1);
	}
	fdpath.path1 = NULL;
	fdpath.path2 = NULL;
	ft_pipex(fdpath, argv, env);
	close(fdpath.fd1);
	close(fdpath.fd2);
	return (0);
}
