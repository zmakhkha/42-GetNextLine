/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:36 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/02 18:45:16 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *fill_buffer(int fd, char *buff)
{
	char *tmp;
	int	i;
	int	buff_len;
	int size;
	char *res;


	buff_len = ft_strlen(buff);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	size = read(fd, tmp, BUFFER_SIZE);
	res = malloc(size + buff_len + 1);
	i = 0;
	
	if (size == -1)
		return NULL;
	while (i < buff_len)
	{
		res[i] = buff[i];
		i++;
	}
	
	i = 0;
	tmp[BUFFER_SIZE] = 0;
	while (tmp[i])
	{
		res[buff_len + i] = tmp[i];
		i++;
	}
	res[buff_len + i] = 0;
	//buff[buff_len + i] = '\0';
	//write(1, tmp, ft_strlen(tmp));
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, buff, ft_strlen(buff));
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, res, ft_strlen(res));
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//free(buff);
	free(tmp);
	return(res);
}

char	*update_buffer(char *buff)
{
	char	*res;
	char	*t;
	int		len;
	int		l;
	int		i;
	len = ft_size_len(buff, 1) + 1;
	l = ft_strlen(buff) - (len + 1);
	res = (char *)malloc(l + 1);
	i = 0;
	while (buff[len])
	{
		res[i] = buff[len];
		printf("asciiii===>%c\n", res[i]);
		len++;
		i++;
	}
	res[i] = '\0';
	//write(1, "\nbuff : ", ft_strlen("\nbuff : "));
	//write(1, buff, ft_strlen(buff));
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	
	//write(1, "\nres : ", ft_strlen("\nres : "));
	//write(1, res, ft_strlen(res));
	t = ft_strdup(res);
	res = ft_substr(buff, len + 1, ft_strlen(buff));
	int jndex = 0;
	while (res[jndex++])
		t[jndex] = res[jndex];
	
	//free(buff);
	return (t);
}
char	*get_next_line(int fd)
{
	static char *buff;
	int			i;
	char		*line = NULL;
	int			new_line_index;
	static int  reminder = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, buff, 0))
		return (NULL);
	i = 0;
	if(!buff)
		buff = calloc(1, 1);
	while (!found_new_line(buff))
		buff = fill_buffer(fd, buff);
	//write(1, buff, ft_strlen(buff));
	new_line_index = ft_size_len(buff, 1);
	line = ft_substr(buff, 0, new_line_index + 1);
	//write(1, "\n+++++++++>> buff : ", ft_strlen("\n+++++++++>> buff : "));
	//write(1, buff, ft_strlen(buff));
	//write(1, "|\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	//write(1, "\n", 1);
	buff = update_buffer(buff);

	return(line);
}


int main()
{
	char *lineee;
	int fd = open("./file", O_RDONLY, 0755);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
}