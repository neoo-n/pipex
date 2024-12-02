/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/02 16:42:26 by dvauthey         ###   ########.fr       */
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
	fd1 = open(argv[1], O_RDONLY | O_CREAT);
	fd2 = open(argv[4], O_RDONLY | O_CREAT);
//	ft_pipex(fd1, fd2, argv, env);
	close(fd1);
	close(fd2);
	return (0);
}