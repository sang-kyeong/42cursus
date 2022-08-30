/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:17 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 15:57:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			put_s(char *s);
const void	build_buffer(char *buf, unsigned long long value, size_t buf_size);

int	put_p(void *p)
{
	char	buffer[19];

	ft_strlcpy(buffer, "0x", 19);
	build_buffer(buffer, (unsigned long long)p, 19);
	return (put_s(buffer));
}

const void	build_buffer(char *buf, unsigned long long value, size_t buf_size)
{
	char	digit[2];

	if (value / 16)
		build_hex(buf, value / 16, buf_size);
	value %= 16;
	if (value >= 10)
		digit[0] = value - 10 + 'a';
	else
		digit[0] = value + '0';
	digit[1] = '\0';
	ft_strlcat(buf, digit, buf_size);
}
