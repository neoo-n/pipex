/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:01:13 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/02 16:40:38 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*getting_env(char **env)
{
	int		i;
	char	*paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			paths = ft_strdup(env[i]);
		i++;
	}
	return (paths + 5);
}

static void	freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*accessing_path(char *cmd, char **env)
{
	int		i;
	char	**result;
	char	*pathc;

	i = 0;
	result = ft_split(getting_env(env), ':');
	if (!result || !result[0])
		return (freesplit(result), NULL);
	pathc = NULL;
	while (result[i])
	{
		pathc = ft_strjoin(result[i], "/");
		pathc = ft_strjoin(pathc, cmd);
		if (access(pathc, F_OK) == 0)
			return (freesplit(result), pathc);
		i++;
	}
	freesplit(result);
	return (pathc);
}
