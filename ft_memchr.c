/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:33:49 by habouda           #+#    #+#             */
/*   Updated: 2024/05/11 01:29:03 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_str;
	unsigned char	ptr_c;

	ptr_str = (unsigned char *)str;
	ptr_c = (unsigned char)c;
	while (i < n)
	{
		if (*ptr_str == ptr_c)
			return (ptr_str);
		ptr_str++;
		i++;
	}
	return (NULL);
}

/*Used *ptr_str and ptr_c to cast
 *str and c to unsigned char and use them since memory blocks
  opperates on unsigned char
 */