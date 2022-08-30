/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/11 00:00:25 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "format_bonus.h"

int			calc_fill_len(char *buffer, t_format format);
void		init_prefix(char *prefix, t_format format, int is_minus);
void		init_padding(t_padding *padding, t_format format, int s_len);
int			print_buffer(t_padding padding, char *prefix, size_t fill_len, char *buffer);

static void	build_buffer(char *buffer, unsigned int value, size_t buf_size, char a);

// 0	: fill 0 padding
// .*	: min width of value
// *	: min width of output
// -	: right align with width
// +	: + a head of value
// sp	: sp a head of value
// #	: Undefined

int	put_x(unsigned int x, t_format format)
{
	char		buffer[9];
	int			fill_len;
	char		prefix[3];
	t_padding	padding;

	build_buffer(buffer, x, 9, format.specifier);
	fill_len = calc_fill_len(buffer, format);
	init_prefix(prefix, format, 0);
	init_padding(&padding, format,
		ft_strlen(prefix) + fill_len + ft_strlen(buffer));
	return (print_buffer(padding, prefix, fill_len, buffer));
}

static void	build_buffer(char *buffer, unsigned int value, size_t buf_size, char z)
{
	const char	*lower_hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	char		digit[2];

	if (value / 16)
		build_buffer(buffer, value / 16, buf_size, z);
	value %= 16;
	if (z == 'x')
		digit[0] = lower_hex[value];
	else
		digit[0] = upper_hex[value];
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buf_size);
}
