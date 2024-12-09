/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitpipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:55:15 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/09 11:55:15 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_nb_row(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
				i++;
			}
			else
				while (s[i] && s[i] != c)
					i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static int	ft_nb(const char *s, char c, int i, int *start)
{
	while (s[i] == c && s[i])
		i++;
	*start = i;
	if (s[i] == '\'')
	{
		i++;
		while (s[i] != '\'')
			i++;
		i++;
	}
	else
		while (s[i] != c && s[i])
			i++;
	return (i);
}	

static char	*ft_strinrow(char const *s, int start, int end)
{
	char	*row;
	int		i;

	i = 0;
	row = malloc((end - start + 1) * sizeof(char));
	if (row == NULL)
		return (NULL);
	while (i < (end - start))
	{
		row[i] = s[start + i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

void	*ft_freesplit(char **res, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_splitpipex(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	start = 0;
	result = malloc((ft_nb_row(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		i = ft_nb(s, c, i, &start);
		if (start != i)
		{
			result[j] = ft_strinrow(s, start, i);
			if (!result[j])
				return (ft_freesplit(result, j));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
