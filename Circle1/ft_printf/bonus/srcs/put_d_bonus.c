/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:26 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 23:42:06 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "format_bonus.h"

int			calc_fill_len(char *buffer, t_format format);
void		init_prefix(char *prefix, t_format format, int is_minus);
void		init_padding(t_padding *padding, t_format format, int s_len);
int			print_buffer(t_padding padding, char *prefix, size_t fill_len, char *buffer);

static void	build_buffer(char *buffer, int value, size_t buf_size);

int	put_d(int d, t_format format)
{
	char		buffer[12];
	int			fill_len;
	char		prefix[3];
	t_padding	padding;

	build_buffer(buffer, d, 12);
	fill_len = calc_fill_len(buffer, format);
	init_prefix(prefix, format, d < 0);
	init_padding(&padding, format,
		ft_strlen(prefix) + fill_len + ft_strlen(buffer));
	return (print_buffer(padding, prefix, fill_len, buffer));
}

static void	build_buffer(char *buffer, int value, size_t buf_size)
{
	char	digit[2];

	if (value < 0)
	{
		if (value / 10)
			build_buffer(buffer, -(value / 10), buf_size);
		digit[0] = -(value % 10) + '0';
	}
	else
	{
		if (value / 10)
			build_buffer(buffer, value / 10, buf_size);
		digit[0] = value % 10 + '0';
	}
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buf_size);
}
