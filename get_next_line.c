/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:40:37 by vnxele            #+#    #+#             */
/*   Updated: 2017/12/02 13:04:22 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **line, char **cache, int j)
{
	int i;
	char *tmp;

	i = 0;
	int k = ft_strlen(*line);
	tmp = *line;	
	*line = ft_strnew(k);
	while(tmp[i] != '\n')
	{
		(*line)[i] = tmp[i];
		i++;
	}
	return(1);
}

int		get_next_line(int fd, char **line)
{
	int j;
	static char *cache;
	char		*buff;

	buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || *line == NULL)
		return (-1);
	if (*line)
	{
		int k = ft_strlen(*line);
		ft_bzero(*line, k);
	}
	//if (cache)
	//{
	//	*line = ft_strcat(cache, *line);
	//	return(1);
	//}
	while ((j = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (buff[0] == '\n')
			return(1);

		buff[j] = '\0';
		*line = ft_strcat(*line, buff);
		if (ft_strchr(*line, '\n'))
		{
			//if (cache)
			//{
			//	printf("Cache: %s\n", cache);
			//	get_line(line, &cache, j);
			//	*line = ft_strcat(cache, *line);
			//	return(1);
			//}
			cache = ft_strchr(*line, '\n');
			return(get_line(line, &cache, j));
		}
	}
	return(0);
}

int		main()
{
	char *line;
	int  fd;

	fd = open("poem.txt", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		//ft_putendl("_______");
	}
	return (0);
}
