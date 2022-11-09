/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:33:05 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/09 13:50:41 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_readline(int fd, char **line, char *buf, ssize_t *read_size)
{
	char		*tmp;

	while (1)
	{
		tmp = ft_strjoin(*line, buf);
		free(*line);
		if (!tmp)
			return (NULL);
		*line = tmp;
		if (ft_strchr(*line, '\n'))
			return (*line);
		*read_size = read(fd, buf, BUFFER_SIZE);
		if (*read_size == -1)
			return (ft_free(line));
		buf[*read_size] = '\0';
		if (*read_size == 0 && *line[0] == '\0')
			return (ft_free(line));
		if (*read_size == 0)
			return (*line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		read_size;
	static char	buf[BUFFER_SIZE + 1ul];
	char		*line;
	char		*tmp;
	char		*new_line_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (!ft_readline(fd, &line, buf, &read_size))
		return (NULL);
	if (!read_size)
		return (line);
	new_line_ptr = ft_strchr(line, '\n');
	ft_memmove(buf, new_line_ptr + 1, ft_strlen(new_line_ptr));
	tmp = ft_substr(line, 0, (new_line_ptr + 1) - line);
	free(line);
	if (!tmp)
		return (NULL);
	line = tmp;
	return (line);
}
