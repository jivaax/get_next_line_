/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:49 by juliannawir       #+#    #+#             */
/*   Updated: 2026/01/09 14:48:48 by jwira            ###   ########.fr       */
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
		new_stash = ft_strdup(stash + i + 1);
		if (!new_stash)
			return (NULL);
		stash[i + 1] = '\0';
	}
	else
		new_stash = NULL;
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
		free (temp);
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

	line = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash);
		free (buf);
		stash = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line(fd, stash, buf);
	free (buf);
	buf = NULL;
	if (!line || line[0] == '\0')
		return (free(line), stash = NULL, NULL);
	stash = cut_line(line);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//	char 	*line;
//
//	fd = open("get_next_line.c", O_RDONLY);
//	if (fd == -1)
//		return (1);
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}