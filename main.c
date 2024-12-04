/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/04 14:23:54 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd[2];

	if (argc != 5 || !env)
	{
		write(2, "Error : not enough arguments\n", 30);
		return (1);
	}
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		perror("Error opening/creating files");
	fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0744);
	if (fd[1] == -1)
	{
		close(fd[0]);
		perror("Error opening/creating file");
	}
	ft_pipex(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
