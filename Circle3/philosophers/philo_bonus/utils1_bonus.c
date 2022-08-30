/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:30 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/27 17:59:38 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <limits.h>

size_t	get_ms_from(struct timeval from)
{
	struct timeval	tv;
	size_t			ms;

	while (gettimeofday(&tv, NULL) != 0)
		;
	ms = (tv.tv_sec - from.tv_sec) % 100000 * 1000;
	ms += (tv.tv_usec - from.tv_usec) / 1000;
	return (ms);
}

int	parse_uint(unsigned int *ptr, char *str)
{
	size_t	value;

	if ('9' < *str || *str < '0')
		return (-1);
	value = 0;
	while ('0' <= *str && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		if (value > UINT_MAX)
			return (-2);
		str++;
	}
	if (*str)
		return (-1);
	*ptr = (unsigned int)value;
	return (0);
}

char	*ft_strcat(char *dst, char *src)
{
	char	*dst_org;

	dst_org = dst;
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (dst_org);
}

char	*ft_numcat(char *dst, size_t n)
{
	char	buffer[25];
	char	*ptr;

	buffer[24] = '\0';
	ptr = buffer + 23;
	if (n == 0)
		*ptr = '0';
	else
	{
		while (n)
		{
			*ptr = n % 10 + '0';
			n /= 10;
			ptr--;
		}
		ptr++;
	}
	ft_strcat(dst, ptr);
	return (dst);
}

void	print(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(STDOUT_FILENO, str, len);
}
