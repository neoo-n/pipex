/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:21:41 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/09 11:57:04 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoinfree1(char *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = malloc((i + j + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	**ft_strtrimpipex(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strtrim(tab[i], "'");
		i++;
	}
	return (tab);
}

void	freepathcmd(t_fdpath fdpath, char **cmd, char *message)
{
	free(fdpath.path1);
	free(fdpath.path2);
	if (cmd)
		freesplit(cmd);
	if (message)
		perror(message);
	exit(EXIT_FAILURE);
}
