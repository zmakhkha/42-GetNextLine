/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:09:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/11/30 18:11:12 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE  5
#endif

# include <stdlib.h>
# include <unistd.h>
# include<libc.h>

char *get_next_line(int fd);
size_t	ft_next_lign(const char *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_size_len(const char *a, int b);
int found_new_line(char *a);
char *fill_buffer(int fd, char *buff);
char *get_next_line(int fd);