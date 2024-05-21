/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:10:23 by habouda           #+#    #+#             */
/*   Updated: 2024/05/21 13:26:04 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_size(int	n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n /10;
		i++;
	}
	return (i);
}
char *ft_itoa(int n)
{
	char	*s;
	int		k;
	int 	end;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	k = n_size(n);
	s = malloc (sizeof(char) * (k + 1));
	if (!s)
		return (NULL);
	end = k;
	k = k - 1;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		s[k] = ((n % 10) + '0');
		n = n / 10;
		k--;
	}
	s[k] = '-';
	s[end] = '\0';
	return (s);
}


