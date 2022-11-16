/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:33 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/16 16:59:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_next_lign(const char *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\n') && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}