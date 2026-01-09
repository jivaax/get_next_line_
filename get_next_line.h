/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:15:35 by jwira             #+#    #+#             */
/*   Updated: 2026/01/09 14:30:54 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif