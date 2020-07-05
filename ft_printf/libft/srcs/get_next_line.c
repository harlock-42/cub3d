/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:50:38 by tallaire          #+#    #+#             */
/*   Updated: 2020/02/06 11:50:23 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*stock_cat(char *str, char *buff, int *stop)
{
	int		i;
	int		j;
	int		new_len;
	char	*new;

	i = 0;
	j = 0;
	new_len = ft_strlen_gnl(str) + ft_strlen_gnl(buff);
	if (!(new = malloc(sizeof(char) * (new_len + 1))))
		return (NULL);
	while (str && *(str + i))
	{
		*(new + i) = *(str + i);
		++i;
	}
	while (buff && *(buff + j))
	{
		if (*(buff + j) == '\n')
			*stop = 1;
		*(new + i + j) = *(buff + j);
		++j;
	}
	*(new + i + j) = '\0';
	free(str);
	return (new);
}

static	char	*ft_line(char *src, int *stop)
{
	int		i;
	int		src_len;
	char	*new;

	i = 0;
	src_len = 0;
	while (src && *(src + src_len) && *(src + src_len) != '\n')
		src_len++;
	if (!(new = malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (src && *(src + i) && *(src + i) != '\n')
	{
		*(new + i) = *(src + i);
		++i;
	}
	*(new + i) = '\0';
	if (src && (is_to_c(src, '\n')) <= 0)
		*stop = 2;
	if (!src && *stop == 0)
		*stop = 2;
	return (new);
}

static	char	*ft_realloc_stock(char *src)
{
	int		i;
	int		j;
	int		size;
	char	*new;

	i = 0;
	j = 0;
	while (src && *(src + i))
	{
		if (*(src + i) == '\n')
		{
			i++;
			break ;
		}
		++i;
	}
	size = ft_strlen_gnl(src) - i;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src && *(src + i))
		*(new + j++) = *(src + i++);
	*(new + j) = '\0';
	free(src);
	return (new);
}

static	int		end_of_file(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				stop;
	int				ret;
	char			*tmp_line;
	char			buff[BUFFER_SIZE + 1];
	static	char	*stock = NULL;

	stop = 0;
	if (fd < 0 || (read(fd, buff, 0)) < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		*(buff + ret) = '\0';
		if (!(stock = stock_cat(stock, buff, &stop)))
			return (ft_error(&stock, NULL));
		if (stop == 1)
			break ;
	}
	if (!(tmp_line = ft_line(stock, &stop)))
		return (ft_error(&stock, NULL));
	if (!(stock = ft_realloc_stock(stock)))
		return (ft_error(&stock, &tmp_line));
	*line = tmp_line;
	if (stop == 2)
		return (end_of_file(&stock));
	return (1);
}
