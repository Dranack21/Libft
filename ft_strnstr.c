/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:36:49 by habouda           #+#    #+#             */
/*   Updated: 2024/05/24 12:01:50 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t slen)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] && i < slen)
	{
		while (little[j] == big[i] && little[j] && big[i] && i < slen)
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - ft_strlen(little)]);
		j = 0;
		k++;
		i = k;
		if (little[j] != big[i])
			i++;
	}
	return (NULL);
}

