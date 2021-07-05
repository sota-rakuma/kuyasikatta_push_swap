/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:58:34 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/30 15:24:22 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	get_new_str(char **line, char *buff, char *nl, char **rest)
{
	char	*tmp1;
	char	*tmp2;

	tmp2 = ft_substr_for_gnl(buff, nl);
	if (!tmp2)
	{
		free(buff);
		return (-1);
	}
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp2);
	free(tmp1);
	free(tmp2);
	if (*(nl + 1) != '\0')
		*rest = ft_strdup_for_gnl(nl + 1);
	if (*(nl + 1) != '\0' && *rest == NULL)
		return (-1);
	if (*line == NULL)
	{
		free(buff);
		return (-1);
	}
	free(buff);
	return (1);
}

static ssize_t	join_til_nl(int fd, char **line, char **rest)
{
	char	*tmp1;
	ssize_t	nbytes;
	char	*nl;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	while (buff && *line)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes <= 0)
		{
			free(buff);
			return (nbytes);
		}
		buff[nbytes] = '\0';
		nl = ft_strchr(buff, '\n');
		if (nl)
			return (get_new_str(line, buff, nl, rest));
		tmp1 = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp1);
	}
	free(buff);
	return (-1);
}

static ssize_t	proc_of_rest(int fd, char **line, char **rest)
{
	char	*nl;
	char	*tmp_for_rest;
	char	*tmp_for_line;

	nl = ft_strchr(*rest, '\n');
	if (nl)
	{
		tmp_for_rest = *rest;
		*rest = NULL;
		return (get_new_str(line, tmp_for_rest, nl, rest));
	}
	tmp_for_line = *line;
	*line = ft_strjoin(tmp_for_line, *rest);
	free(tmp_for_line);
	free(*rest);
	*rest = NULL;
	return (join_til_nl(fd, line, rest));
}

int	get_next_line(int fd, char **line)
{
	static char	*rest[MAXFD];
	ssize_t		flag;

	if (fd < 0 || MAXFD < fd || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup_for_gnl("");
	if (!(*line))
		return (-1);
	if (rest[fd])
		flag = proc_of_rest(fd, line, &rest[fd]);
	else
		flag = join_til_nl(fd, line, &rest[fd]);
	if (flag < 0)
	{
		free(*line);
		*line = NULL;
	}
	if (flag <= 0)
		return ((int)flag);
	return (1);
}
