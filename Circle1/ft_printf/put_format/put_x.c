/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 15:56:18 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			put_s(char *s);
const void	build_buffer(char *buffer, unsigned int value, size_t buf_size);

int	put_x(int x)
{
	char			buffer[9];

	buffer[0] = '\0';
	build_buffer(buffer, (unsigned int)x, 9);
	return (put_s(buffer));
}

const void	build_buffer(char *buffer, unsigned int value, size_t buf_size)
{
	char	digit[2];

	if (value / 16)
		build_buffer(buffer, value / 16, buf_size);
	value %= 16;
	if (value >= 10)
		digit[0] = value - 10 + 'a';
	else
		digit[0] = value + '0';
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buf_size);
}
