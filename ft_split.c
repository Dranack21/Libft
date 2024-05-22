/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:48:43 by habouda           #+#    #+#             */
/*   Updated: 2024/05/22 15:03:31 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_pos(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}


int	count_words(const char *str, char c)
{
	int	i;
	int	words;
	int	j;

	i = 0;
	words = 0;
	j = 0;
	if (!str)
		return (0);
	if (!c)
		return (1);
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			words++;
			j = 1;
		}
		else
			j = 0;
		i++;
	}
	return (words);
}

void	allocation(char **split, const char *s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		split[j] = (char *)&s[j];
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	split = malloc(sizeof(char) * count_words(s,c) + 1);
	if (!split)
		return (NULL);
	while(*s)
	{
		i = char_pos (s, c);
		split[j] = malloc(sizeof(char) * i + 1);
		if (!split[j])
			return (NULL);
		allocation(&split[j], s, i);
		s = s + i + 1;
		j++;
	}
	return (split);
}
