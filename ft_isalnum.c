/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Habouda <Habouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:22:35 by Habouda           #+#    #+#             */
/*   Updated: 2024/04/27 23:17:36 by Habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if (((c <= 90 && c >= 65) || (97 <= c && c <= 122)) || (c < 58 && c > 47))
		return (1);
	else
		return (0);
}
