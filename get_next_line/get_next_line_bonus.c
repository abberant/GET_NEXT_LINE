/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:51:16 by aanouari          #+#    #+#             */
/*   Updated: 2022/12/27 00:43:51 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[1024];

	if (fd < 0 || BUFFER_SIZE < 1
		|| BUFFER_SIZE == 2147483647 || read(fd, 0, 0) < 0)
	{
		free(store[fd]);
		store[fd] = NULL;
		return (store[fd]);
	}
	store[fd] = ft_readadd_to_store(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_cull_line(store[fd]);
	store[fd] = ft_cull_extra(store[fd]);
	return (line);
}

char	*ft_readadd_to_store(int fd, char *store)
{
	int		scan;
	char	*depo;

	depo = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!depo)
		return (NULL);
	scan = 1;
	while (!ft_strchr(store, '\n') && scan)
	{
		scan = read(fd, depo, BUFFER_SIZE);
		if (scan == -1)
		{
			free(depo);
			return (NULL);
		}
		depo[scan] = '\0';
		store = ft_strjoin(store, depo);
	}
	free(depo);
	return (store);
}

char	*ft_cull_line(char *store)
{
	size_t	i;
	char	*line;

	if (!(*store))
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		line[i] = store[i];
	return (line);
}

char	*ft_cull_extra(char *store)
{
	size_t	rid;
	size_t	keep;
	char	*remain;

	rid = 0;
	while (store[rid] && store[rid] != '\n')
		rid++;
	if (!store[rid])
	{
		free(store);
		return (NULL);
	}
	remain = ft_calloc(ft_strlen(store) - rid + 1, sizeof(char));
	if (!remain)
		return (NULL);
	rid++;
	keep = 0;
	while (store[rid])
		remain[keep++] = store[rid++];
	free(store);
	return (remain);
}