/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:39:36 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/15 22:17:11 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*ft_read(char *line, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	i;

	while (ft_strchr(line, '\n') == 1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (i < BUFFER_SIZE)
		{
			line = ft_update_strjoin(line, buf, i);
			break ;
		}
		buf[i] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*ft_update_buf(char *line)
{
	int		full_len;
	int		line_len;
	int		k;
	char	*ret;

	full_len = ft_strlen(line, 0);
	line_len = ft_strlen(line, 1);
	k = 0;
	ret = malloc((full_len - line_len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (full_len - line_len > 0)
	{
		ret[k] = line[line_len];
		line_len++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_kindofsplitbutmorelikeacpy(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(ft_strlen(line, 1) + 2);
	if (tmp == NULL)
		return (NULL);
	if (ft_strlen(line, 1) == 0)
		return (NULL);
	while (line[i] != '\n' && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line != NULL)
		next_line = ft_update_buf(line);
	line = ft_read(next_line, fd);
	return (ft_kindofsplitbutmorelikeacpy(line));
}

int	main(int ac, char **av)
{
	char  *line;
	int   fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	//while (fd)
	//{
		line = get_next_line(fd);
		printf("premiere ligne :%s", line);
		line = get_next_line(fd);
		printf("deuxieme ligne :%s", line);
		line = get_next_line(fd);
		printf("troisieme ligne :%s", line);
		line = get_next_line(fd);
		printf("quatrieme ligne :%s", line);
		line = get_next_line(fd);
		printf("cinquieme ligne :%s", line);
	//}

	return (0);
}
