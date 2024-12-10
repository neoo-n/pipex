/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:01:13 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/10 11:57:12dvauthey         ###   ########.fr       */
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

void	freesplit(char **tab)
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
	if (!env_cut)
		return ;
	*paths = ft_split(env_cut, ':');
	if (!(*paths) || !(*paths)[0])
		return ;
	*cmdsplit = ft_split(cmd, ' ');
	if (!(*cmdsplit) || !(*cmdsplit)[0])
		return (freesplit(*paths));
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
	if (!cmdsplit || !paths)
		return (NULL);
	while (paths[i])
	{
		path_right = ft_strjoinpipex(paths[i], cmdsplit[0]);
		if (!path_right)
			return (freesplit(paths), freesplit(cmdsplit), NULL);
		if (access(path_right, F_OK) == 0)
			return (freesplit(paths), freesplit(cmdsplit), path_right);
		i++;
		free(path_right);
	}
	return (freesplit(paths), freesplit(cmdsplit), NULL);
}
