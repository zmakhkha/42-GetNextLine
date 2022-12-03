/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:36 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/03 17:39:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*fill_buffer(int fd, char *buff, int *size)
{
	char	*tmp;
	int		i;
	int		buff_len;
	char	*res;

	buff_len = ft_strlen(buff);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*size = read(fd, tmp, BUFFER_SIZE);
	res = ft_calloc(1, *size + buff_len + 1);
	i = -1;
	if (*size == -1)
		return (NULL);
	while (++i < buff_len)
		res[i] = buff[i];
	if (*size == 0)
		return (res);
	i = -1;
	tmp[BUFFER_SIZE] = 0;
	while (tmp[++i])
		res[buff_len + i] = tmp[i];
	res[buff_len + i] = 0;
	free(tmp);
	return (res);
}

char	*update_buffer(char *buff)
{
	char	*res;
	int		lign_index;

	lign_index = ft_size_len(buff, 1) + 1;
	res = ft_substr(buff, lign_index, ft_strlen(buff));
	free (buff);
	return (res);
}

int	found_new_line(char *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			_size;
	int			new_line_index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, buff, 0))
		return (NULL);
	_size = 4;
	if (!buff)
		buff = ft_calloc(1, 1);
	while (!found_new_line(buff) && _size)
		buff = fill_buffer(fd, buff, &_size);
	if (!_size)
		return (NULL);
	new_line_index = ft_size_len(buff, 1);
	line = ft_substr(buff, 0, new_line_index + 1);
	buff = update_buffer(buff);
	return (line);
}
