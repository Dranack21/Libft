/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:36:49 by habouda           #+#    #+#             */
/*   Updated: 2024/05/16 14:07:15 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t		i;
	size_t		j;
	char		*temp;
	char		*str2;

	i = 0;
	j = 0;
	temp = (char *)find;
	str2 = (char *)str;
	if (temp[j] == '\0')
		return (str2);
	while (str2[i])
	{
		while (temp[j] == str2[i] && temp[j] && str2[i] && i <= slen)
		{	
			j++;
			i++;
		}
		if (temp[j] == '\0')
			return (str2);
		j = 0;
		if (temp[j] != str2[i])
			i++;
	}
	return (NULL);
}
