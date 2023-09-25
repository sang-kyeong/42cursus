/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:27:12 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 16:28:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

void	ft_bzero(void *s, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (size--)
		*p++ = 0;
}

int	make_decimal(char *buffer, long value)
{
	int	offset;

	offset = 0;
	if (value / 10)
		offset += make_decimal(buffer, value / 10);
	else if (value < 0)
		buffer[offset++] = '-';
	if (value < 0)
		value *= -1;
	buffer[offset++] = (value % 10) + '0';
	return (offset);
}

void	make_lowerhex(char *buffer, unsigned long value)
{
	const char	*hex = "0123456789abcdef";
	int			offset;
	int			div;

	if (!value)
	{
		buffer[0] = '0';
		return ;
	}
	offset = 0;
	div = 16 * 4;
	while (div)
	{
		div -= 4;
		if (value >> div)
			buffer[offset++] = hex[(value >> div) % 16];
	}
}

void	make_upperhex(char *buffer, unsigned long value)
{
	const char	*hex = "0123456789ABCDEF";
	int			offset;
	int			div;

	if (!value)
	{
		buffer[0] = '0';
		return ;
	}
	offset = 0;
	div = 16 * 4;
	while (div)
	{
		div -= 4;
		if (value >> div)
			buffer[offset++] = hex[(value >> div) % 16];
	}
}
