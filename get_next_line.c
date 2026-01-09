/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwira <jwira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:47:49 by juliannawir       #+#    #+#             */
/*   Updated: 2026/01/09 13:31:04 by jwira            ###   ########.fr       */
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
		new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
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
	line = stash;
	stash = cut_line(line);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//
//	fd = open("file.txt", O_RDONLY);
//	if (fd == -1)
//		return (1);
//	printf("GNL 1: %s", get_next_line(fd));
//	printf("GNL 2: %s", get_next_line(fd));
//	printf("GNL 3: %s", get_next_line(fd));
//	printf("GNL 4: %s", get_next_line(fd));
//	printf("GNL 5: %s", get_next_line(fd));
//	printf("GNL 6: %s", get_next_line(fd));
//	printf("GNL 7: %s", get_next_line(fd));
//	printf("GNL 8: %s", get_next_line(fd));
//	printf("GNL 9: %s", get_next_line(fd));
//	printf("GNL 10: %s", get_next_line(fd));
//	printf("GNL 11: %s", get_next_line(fd));
//	printf("GNL 12: %s", get_next_line(fd));
//	printf("GNL 13: %s", get_next_line(fd));
//	printf("GNL 14: %s", get_next_line(fd));
//	return (0);
//}
