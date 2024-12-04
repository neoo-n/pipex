/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:35:16 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/04 15:32:39 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/src/libft.h"

char	*ft_strjoinfree1(char *s1, char const *s2);
void	freesplit(char **tab);
char	*accessing_path(char *cmd, char **env);
void	ft_pipex(int *fd, char **argv, char **env);

#endif