/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:36 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/16 17:34:35 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buff;
	char *res;
	int a;

	if (fd < 0 || !read(fd, buff, 0))
		return (NULL);
	//a = read(fd, buff, BUFFERSIZE);
	
}