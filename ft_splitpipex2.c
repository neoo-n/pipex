/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitpipex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:58:02 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/10 14:56:38 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	double_single_quote(const char *s, int i)
{
	if (s[i] == '\"')
	{
		i++;
		while (s[i])
		{
			if (s[i - 1] == '\\' && s[i] == '\'')
				break;
			i++;
		}
	}
	else if (s[i] == '\'')
	{
		i++;
		while (s[i])
		{
			if (s[i - 1] == '\\' && s[i] == '\'')
				break ;
			i++;
		}
	}
	if (s[i])
		i++;
	return (i);
}

int	ft_nb_row(char const *s, char c)
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
			if (s[i] == '\'' || s[i] == '\"')
				i = double_single_quote(s, i);
			else
				while (s[i] && s[i] != c)
					i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}
