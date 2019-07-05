/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:56:21 by blomo             #+#    #+#             */
/*   Updated: 2019/04/26 13:26:01 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char **str)
{
	int i;

	i = 0;
	while (*(*(str) + i) != '\n')
		i++;
	return (i);
}

static int	ft_findn(char **str, char **line)
{
	char	*temp;
	char	*temp1;
	int		i;

	if (**str == '\0')
		return (0);
	if ((ft_strchr(*str, '\n')) != NULL)
	{
		i = ft_count(&str[0]);
		temp = ft_strsub(*str, 0, i);
		temp1 = ft_strdup(ft_strchr(*str, '\n') + 1);
		free(*str);
		*line = ft_strdup(temp);
		free(temp);
		if (temp1)
			*str = ft_strdup(temp1);
		free(temp1);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_memdel((void **)str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*str[BUF_MAX];
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	temp = NULL;
	if (fd == -1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (str[fd] == 0)
		str[fd] = ft_strnew(0);
	while (ft_strchr(str[fd], '\n') == NULL)
	{
		rd = read(fd, buff, BUFF_SIZE);
		buff[rd] = '\0';
		if (rd == 0)
			break ;
		temp = ft_strjoin(str[fd], (const char *)buff);
		free(str[fd]);
		str[fd] = ft_strdup(temp);
		if (str[fd] == 0)
			str[fd] = ft_strnew(0);
		free(temp);
		temp = NULL;
	}
	return (ft_findn(&str[fd], line));
}
