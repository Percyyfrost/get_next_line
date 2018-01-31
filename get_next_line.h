/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:17:29 by vnxele            #+#    #+#             */
/*   Updated: 2018/01/30 15:17:16 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_static
{
	char		*cache;
	char		*temp;
	char		*temp1;
	char		*temp2;
}				t_static;

int				get_next_line(int fd, char **line);

#endif
