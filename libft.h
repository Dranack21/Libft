/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Habouda <Habouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:55:55 by Habouda           #+#    #+#             */
/*   Updated: 2024/04/27 23:53:45 by Habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isalnum(char c);
int		ft_isalpha(char c);
int		ft_isacii(int c);
int		ft_isdigit(char c);
int		ft_isprint(char c);
int		ft_strlen(char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif
