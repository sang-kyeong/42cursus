/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:32 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/24 18:36:08 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// functions in [get_next_line_utils.c]
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strndup(const char *s, size_t n);

// functions in [get_next_line.c] (here)
char	*append_buffer(char *memory, char *buffer, ssize_t read_len);
char	*pop_line(char **memory);

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buffer;
	ssize_t		read_len;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (!memory)
		memory = ft_strndup("", 0);
	while (memory && !ft_strchr(memory, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len > 0)
			memory = append_buffer(memory, buffer, read_len);
		else if (read_len == 0)
			break ;
		else
		{
			free(memory);
			memory = NULL;
		}
	}
	free(buffer);
	buffer = pop_line(&memory);
	return (buffer);
}

char	*append_buffer(char *memory, char *buffer, ssize_t read_len)
{
	size_t	mem_len;
	char	*new_memory;

	mem_len = ft_strlen(memory);
	new_memory = malloc(mem_len + read_len + 1);
	if (!new_memory)
		return (NULL);
	ft_memcpy(new_memory, memory, mem_len);
	ft_memcpy(new_memory + mem_len, buffer, read_len);
	new_memory[mem_len + read_len] = '\0';
	return (new_memory);
}

char	*pop_line(char **memory)
{
	char	*line;
	char	*rest;
	char	*nl;

	if (!*memory || ft_strlen(*memory) == 0)
	{
		free(*memory);
		*memory = NULL;
		return (NULL);
	}
	nl = ft_strchr(*memory, '\n');
	if (!nl || !*(nl + 1))
	{
		line = *memory;
		*memory = NULL;
	}
	else
	{
		line = ft_strndup(*memory, (size_t)(nl - *memory + 1));
		rest = ft_strndup(nl + 1, -1);
		if (!line || !rest)
		{
			free(line);
			free(rest);
			return (NULL);
		}
		free(*memory);
		*memory = rest;
	}
	return (line);
}
