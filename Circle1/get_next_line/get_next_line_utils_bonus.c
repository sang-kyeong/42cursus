/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:48:53 by sangkkim          #+#    #+#             */
/*   Updated: 2021/12/21 11:59:26 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s += 1;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (src[len] && len + 1 < dstsize)
	{
		dst[len] = src[len];
		len += 1;
	}
	dst[len] = '\0';
	while (src[len])
		len += 1;
	return (len);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (str_len > len)
		str_len = len;
	dup = malloc(sizeof(char) *(str_len + 1));
	if (dup)
		ft_strlcpy(dup, s, str_len + 1);
	return (dup);
}
