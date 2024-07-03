/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:37:42 by habouda           #+#    #+#             */
/*   Updated: 2024/07/03 19:38:23 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = malloc(sizeof(char) * i + 2); /*I +2 car 1 byute pour /n et 1 pour NULL*/
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 2);
	return (line);
}

static	char	*clear_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0') /*PERMET DE DIFFERENCIER LES CAS OU LA LIGNE TERMINE PAR /n et les fois ou non (ie toute derniere ligne)*/
	{
		new_stash = ft_strdup(&stash[i]);
		free (stash);
		stash = NULL;
		if (new_stash[0] == '\0')
		{
			free (new_stash);
			return (NULL);
		}
		return (new_stash);
	}
	else
	{
		new_stash = ft_strdup(&stash[i + 1]);  
		free (stash); /*important je faisait pas*/
		stash = NULL;
		return (new_stash);
	}
}

static char	*read_and_fill_stash(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0'; /*bien penser a le faire sinon on va trop lire hihihihi (tuez moi)*/
		if (!stash)
			stash = ft_strdup("");
		temp = ft_strdup(stash);
		free (stash); /*free qui n'etais pas realiser donc memleaks KO 3eme test*/
		stash = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_and_fill_stash(fd, stash); 
	if (!stash || stash[0] == '\0') /*bien penser a stash[0] pour check les cas ou stash vide*/
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = fill_line (stash);
	stash = clear_stash(stash);
	return (line);
}