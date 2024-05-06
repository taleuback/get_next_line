/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocrobin <ocrobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:06:27 by ocrobin           #+#    #+#             */
/*   Updated: 2024/05/06 14:53:05 by ocrobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int	ft_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

void	cutbuf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
	{
		i++;
	}
	if (buf[i] == '\n')
	{
		i++;
		while (buf[i] != '\0')
		{
			buf[j] = buf[i];
			j++;
			i++;
		}
	}
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	int			bytes;
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (line && *line)
				return (line);
			return (NULL);
		}
		buf[bytes] = '\0';
		if (ft_eol(buf))
		{
			line = ft_strjoin(line, buf);
			cutbuf(buf);
			return (line);
		}
		else
			line = ft_strjoin(line, buf);
	}
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("bible.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
