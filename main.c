/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/03 10:01:24 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd1;
	int	fd2;

	if (argc != 5 || !env)
	{
		write(2, "Error : not enough arguments\n", 30);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		perror("Error opening/creating files");
	fd2 = open(argv[4], O_WRONLY | O_CREAT);
	if (fd2 == -1)
	{
		close(fd1);
		perror("Error opening/creating file");
	}
	ft_pipex(fd1, fd2, argv, env);
	close(fd1);
	close(fd2);
	return (0);
}
