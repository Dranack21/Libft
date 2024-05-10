/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:07:36 by habouda           #+#    #+#             */
/*   Updated: 2024/05/11 00:22:25 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *str1, const char *str2, size_t length )
{
	size_t	i;

	i = 0;
	if (length == 0)
	{
		return (0);
	}
	while (str1[i] && str2[i] && i < length - 1)
	{
		if (str1[i] - str2[i] == 0)
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);
}
