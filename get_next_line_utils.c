/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:48:45 by juliannawir       #+#    #+#             */
/*   Updated: 2026/01/09 14:42:51 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	concat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
