/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:49 by juliannawir       #+#    #+#             */
/*   Updated: 2026/01/09 13:58:30 by jwira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut_line(char	*stash)
{
	ssize_t		i;
	char		*new_stash;

	i = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
	{
		stash[i + 1] = '\0';
		new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
		if (!new_stash)
			return (NULL);
	}
	else
		new_stash = NULL;
	free(stash);
	return (new_stash);
}

static char	*fill_line(int fd, char *stash, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!stash)
		stash = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		if (!stash || ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	stash = fill_line(fd, stash, buf);
	free (buf);
	if (!stash || stash[0] == '\0')
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_strdup(stash);
	if (!line)
		return (NULL);
	stash = cut_line(stash);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//	char	*line;

//	fd = open("get_next_line.c", O_RDONLY);
//	if (fd == -1)
//		return (1);
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("GNL 1: %s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
