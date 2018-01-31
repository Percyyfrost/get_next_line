/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:24:13 by vnxele            #+#    #+#             */
/*   Updated: 2018/01/31 10:11:37 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ret_line(t_static *head, char buff[], char **line)
{
	head->cache = ft_strdup(ft_strchr(buff, '\n'));
	head->temp = ft_strsub(buff, 0, ft_strlen(buff) - ft_strlen(head->cache));
	head->temp2 = *line;
	*line = ft_strjoin(*line, head->temp);
	free(head->temp);
	free(head->temp2);
	head->temp = head->cache;
	head->cache = ft_strsub(head->cache, 1, ft_strlen(head->cache));
	free(head->temp);
}

int		get_line(t_static *head, int fd, char **line)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			ret_line(head, buff, line);
			return (1);
		}
		head->temp = *line;
		*line = ft_strjoin(*line, buff);
		free(head->temp);
	}
	if (ret < 0)
		return (ret);
	if (**line)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_static	head;

	if (line == NULL || !(*line = ft_strnew(0)) || fd < 0)
		return (-1);
	if (head.cache)
	{
		free(*line);
		*line = ft_strdup(head.cache);
		if (ft_strchr(*line, '\n'))
		{
			free(head.cache);
			head.cache = ft_strdup(ft_strchr(*line, '\n'));
			head.temp = *line;
			*line = ft_strsub(*line, 0, ft_strlen(*line)
					- ft_strlen(head.cache));
			free(head.temp);
			head.temp = head.cache;
			head.cache = ft_strsub(head.cache, 1, ft_strlen(head.cache));
			free(head.temp);
			return (1);
		}
		head.cache = NULL;
	}
	return (get_line(&head, fd, line));
}
