/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:21:41 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/04 16:12:38 by dvauthey         ###   ########.fr       */
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

static char	*dup_option(int *len_op, char **cmd, char *opt)
{
	int	i;

	i = 1;
	if (len_op[0] != len_op[1])
	{
		opt = ft_strdup(cmd[len_op[0]]);
		while (len_op[0] + i <= len_op[1])
		{
			opt = ft_strjoinfree1(opt, cmd[len_op[0]] + i);
			i++;
		}
	}
	return (opt);

}

char	*ft_splitcmd(char *s)
{
	int		i;
	int		len_op[2];
	char	**cmd;
	char	*opt;

	i = 0;
	opt = NULL;
	cmd = ft_split(s, ' ');
	while (cmd[i])
	{
		if (cmd[i][0] == '\'')
			len_op[0] = i;
		if (cmd[i][ft_strlen(cmd[i] - 1)] == '\'')
			len_op[1] = i;
		i++;
	}
	opt = dup_option(len_op, cmd, opt);
	freesplit(cmd);
	return (opt);
}
