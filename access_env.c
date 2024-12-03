/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:01:13 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/03 11:01:43 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*getting_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
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

static void	split_char(char *cmd, char **env, char ***cmdsplit, char ***paths)
{
	char	*env_cut;

	env_cut = getting_env(env);
	
	*paths = ft_split(env_cut, ':');
	if (!(*paths) || !(*paths)[0])
		return (freesplit(*paths));
	*cmdsplit = ft_split(cmd, ' ');
	if (!(*cmdsplit) || !(*cmdsplit)[0])
		return (freesplit(*paths), freesplit(*cmdsplit));
}

char	*accessing_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	**cmdsplit;
	char	*path_right;

	i = 0;
	path_right = NULL;
	paths = NULL;
	cmdsplit = NULL;
	split_char(cmd, env, &cmdsplit, &paths);
	while (paths[i])
	{
		path_right = ft_strjoin(paths[i], "/");
		path_right = ft_strjoinfree1(path_right, cmdsplit[0]);
		if (access(path_right, F_OK) == 0)
			return (freesplit(paths), freesplit(cmdsplit), path_right);
		i++;
		if (paths[i])
			free(path_right);
	}
	return (freesplit(paths), freesplit(cmdsplit), free(path_right), NULL);
}
