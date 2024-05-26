/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:27:49 by habouda           #+#    #+#             */
/*   Updated: 2024/05/26 00:47:01 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = malloc(sizeof(t_list)* ft_lstsize(lst));
	if (!ptr)
		return (NULL);
	while (lst)
	{
		
	}
	return (ptr);
}
