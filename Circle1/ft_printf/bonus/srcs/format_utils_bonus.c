/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:16:48 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/11 00:31:25 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "format_bonus.h"

int	calc_fill_len(char *buffer, t_format format)
{
	size_t	buffer_len;

	buffer_len = ft_strlen(buffer);
	if (format.f_precision && format.precision > buffer_len)
		return (format.precision - buffer_len);
	else
		return (0);
}

void	init_prefix(char *prefix, t_format format, int is_minus)
{
	ft_bzero(prefix, 3);
	if (is_minus)
		prefix[0] = '-';
	else if (format.f_plus)
		prefix[0] = '+';
	else if (format.f_space)
		prefix[0] = ' ';
	else if (format.f_hash)
	{
		prefix[0] = '0';
		prefix[1] = format.specifier;
	}
	else if (format.specifier == 'p')
	{
		prefix[0] = '0';
		prefix[1] = 'x';
	}
}

int	put_padding(char c, size_t len)
{
	int	printed;

	printed = 0;
	while (len--)
		printed += (int)write(1, &c, 1);
	return (printed);
}

void	init_padding(t_padding *padding, t_format format, int s_len)
{
	padding->minus = format.f_minus;
	if (format.f_width && format.width > (size_t)s_len)
		padding->len = format.width - s_len;
	else
		padding->len = 0;
	if (format.f_zero)
		padding->c = '0';
	else
		padding->c = ' ';
}

int	print_buffer(t_padding padding, char *prefix, size_t fill_len, char *buffer)
{
	int	total_len;

	total_len = padding.len + fill_len;
	if (!padding.minus)
		put_padding(padding.c, padding.len);
	total_len += (int)write(1, prefix, ft_strlen(prefix));
	put_padding('0', fill_len);
	total_len += (int)write(1, buffer, ft_strlen(buffer));
	if (padding.minus)
		put_padding(padding.c, padding.len);
	return (total_len);
}
