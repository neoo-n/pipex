/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:21:41 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/10 10:20:21 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoinpipex(char *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	if (s1)
		if (result[i - 1] != '/')
			result[i] = '/';
	i++;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	**ft_strtrimpipex(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i][0] == '\'' || tab[i][0] == '\"') && ft_strlen(tab[i]) > 1)
			tab[i] = ft_strtrim(tab[i], "'\"");
		i++;
	}
	return (tab);
}

void	error_managefree(t_fdpath fdpath, char **cmd, char *message)
{
	if (fdpath.fd1 > -1)
		close(fdpath.fd1);
	if (fdpath.fd2 > -1)
		close(fdpath.fd2);
	if (fdpath.path1)
		free(fdpath.path1);
	if (fdpath.path2)
		free(fdpath.path2);
	if (cmd)
		freesplit(cmd);
	if (message)
		perror(message);
	exit(EXIT_FAILURE);
}

char	*ft_strcpypipex(char *dest, char *src)
{
	int	i;

	i = 0;
	dest = (char *)ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
