/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/30 18:13:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	char		*s;

	s = (char *)src;
	if (len != 0)
	{
		i = 0;
		len --;
		while (src[i] && i < len)
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, len + 1);
	else
		return (NULL);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	t = (char *)malloc(sizeof(char) * len + 1);
	if (!t)
		return (NULL);
	if (start < ft_strlen(s) && s[start])
		ft_strlcpy(t, s + start, len + 1);
	else
		*t = 0;
	return (t);
}


int	ft_size_len(const char *a, int b)
{
	int	i;

	if (!a)
		return (0);
	
	i = 0;
	if (b)
	{
		while (a[i] != '\n')
			i++;
		return (i);
	}
	else
	{
		while (a[i])
			i++;
		return (i);
	}
}

int found_new_line(char *a)
{
	int	i;

	i = 0;
	while(a[i] && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		return (1);
	return (0);
}

char *fill_buffer(int fd, char *buff)
{
	char *tmp;
	int	i;
	int	buff_len;
	int size;

	tmp = NULL;
 	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	size = read(fd, tmp, BUFFER_SIZE);
	if (size == -1)
		return NULL;
	buff_len = ft_size_len(buff, 0);
	i = 0;
	buff = malloc(size + 1);
	while (i < size)
	{
		buff[buff_len +i] = tmp[i];
		i++;
	}
	buff[buff_len + i] = '\0';

	//free(tmp);
	return(buff);
}

