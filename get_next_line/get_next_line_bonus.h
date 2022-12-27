/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:09 by aanouari          #+#    #+#             */
/*   Updated: 2022/12/19 18:50:04 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_readadd_to_store(int fd, char *store);
char	*ft_cull_line(char *store);
char	*ft_cull_extra(char *store);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
