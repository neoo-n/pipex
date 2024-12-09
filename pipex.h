/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:35:16 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/06 14:26:37 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/src/libft.h"

typedef struct s_fdpath
{
    int     fd1;
    int     fd2;
    char    *path1;
    char    *path2;
}           t_fdpath;

char	*ft_strjoinfree1(char *s1, char const *s2);
void	freesplit(char **tab);
char	*accessing_path(char *cmd, char **env);
char	**ft_splitpipex(char const *s, char c);
void	ft_pipex(t_fdpath fdpath, char **argv, char **env);

#endif