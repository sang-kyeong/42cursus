/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:39:48 by sangkkim          #+#    #+#             */
/*   Updated: 2021/12/23 13:45:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

// get_next_line_utils_bonus.c
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// get_next_line_bonus.c [here]
char	*str_init(t_list **list, int fd);
char	*append_buffer(char *str, char *buf, ssize_t buf_len);
char	*str_save(char *str, t_list **list, int fd);
t_list	*new_list(char *str, int fd, t_list *next);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;
	char			*buffer;
	ssize_t			read_len;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	str = str_init(&list, fd);
	while (str && !ft_strchr(str, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		str = append_buffer(str, buffer, read_len);
		if (read_len < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	str = str_save(str, &list, fd);
	return (str);
}

char	*str_init(t_list **list_ptr, int fd)
{
	t_list	*list;
	char	*str;

	list = *list_ptr;
	if (list == NULL)
		return (ft_strndup("", 1));
	if (list -> fd == fd)
	{
		str = list -> str;
		*list_ptr = list -> next;
		free(list);
		return (str);
	}
	return (str_init(&(list -> next), fd));
}

char	*append_buffer(char *str, char *buf, ssize_t buf_len)
{
	char	*tmp;
	size_t	str_len;

	if (buf_len < 0)
	{
		free(str);
		str = NULL;
	}
	else if (buf_len > 0)
	{
		str_len = ft_strlen(str);
		tmp = malloc(sizeof(char) * (str_len + buf_len + 1));
		if (tmp)
		{
			ft_strlcpy(tmp, str, str_len + 1);
			ft_strlcpy(tmp + str_len, buf, buf_len + 1);
		}
		free(str);
		str = tmp;
	}
	return (str);
}

char	*str_save(char *str, t_list **list, int fd)
{
	t_list	*new;
	char	*tmp;
	size_t	len;

	if (!str || !*str)
	{
		free(str);
		return (NULL);
	}
	tmp = ft_strchr(str, '\n');
	if (!tmp || (tmp && !*(tmp + 1)))
		return (str);
	len = (tmp - str + 1);
	new = new_list(tmp + 1, fd, *list);
	tmp = ft_strndup(str, len);
	if (!new || !tmp)
	{
		free(new);
		free(tmp);
		free(str);
		return (NULL);
	}
	*list = new;
	free(str);
	return (tmp);
}

t_list	*new_list(char *str, int fd, t_list *next)
{
	t_list	*list;
	char	*tmp;

	list = malloc(sizeof(t_list));
	tmp = ft_strndup(str, -1);
	if (!list || !tmp)
	{
		free(list);
		free(tmp);
		return (NULL);
	}
	list -> str = tmp;
	list -> fd = fd;
	list -> next = next;
	return (list);
}
