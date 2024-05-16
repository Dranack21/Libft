/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:47:18 by habouda           #+#    #+#             */
/*   Updated: 2024/05/16 16:55:26 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		i;
	char	*buffer;

	i = ft_strlen(source);
	buffer = malloc(i * sizeof(char) + 1);
	i = 0;
	while (source[i])
	{
		buffer[i] = source[i];
		i++;
	}
	return (buffer);
}
