/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:36 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/30 18:32:55 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"


char *get_next_line(int fd)
{
	static char *buff;
	int			i;
	char		*line;
	int			new_line;
	static int  reminder = 0;
	if (fd < 0)
		return (NULL);
	i = 0;
	if(!buff)
		buff = ft_strdup("");
	while (!found_new_line(buff))
		buff = fill_buffer(fd, buff);
	new_line = ft_size_len( buff, 1);
	printf("%s\n", buff);
	line = ft_substr(buff, 0, new_line+ 1 );
	buff = buff + new_line +1 ;
	return(line);
}

int main()
{
	char *lineee;
	int fd = open("./a", O_RDONLY, 0777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}