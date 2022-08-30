/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:17 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 22:17:21 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "format_bonus.h"

int			calc_fill_len(char *buffer, t_format format);
void		init_prefix(char *prefix, t_format format, int is_minus);
void		init_padding(t_padding *padding, t_format format, int s_len);
int			print_buffer(t_padding padding, char *prefix, size_t fill_len, char *buffer);

static void	build_buffer(char *buffer, unsigned long long value, size_t buf_size);

// 0	: fill 0 padding
// .*	: min width of value
// *	: min width of output
// -	: right align with width
// +	: + a head of value
// sp	: sp a head of value
// #	: Undefined

int	put_p(unsigned long long p, t_format format)
{
	char		buffer[17];
	int			fill_len;
	char		prefix[3];
	t_padding	padding;

	build_buffer(buffer, p, 11);
	fill_len = calc_fill_len(buffer, format);
	init_prefix(prefix, format, 0);
	init_padding(&padding, format,
		ft_strlen(prefix) + fill_len + ft_strlen(buffer));
	return (print_buffer(padding, prefix, fill_len, buffer));
}

static void	build_buffer(char *buf, unsigned long long value, size_t buf_size)
{
	char	digit[2];

	if (value / 16)
		build_buffer(buf, value / 16, buf_size);
	value %= 16;
	if (value >= 10)
		digit[0] = value - 10 + 'a';
	else
		digit[0] = value + '0';
	digit[1] = '\0';
	ft_strlcat(buf, digit, buf_size);
}
