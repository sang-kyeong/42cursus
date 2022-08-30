/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:26 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 15:56:33 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			put_s(char *s);
const void	build_buffer(char *buffer, int value, size_t buf_size);

int	put_d(int d)
{
	char	buffer[12];

	buffer[0] = '\0';
	build_buffer(buffer, d, 12);
	return (put_s(buffer));
}

const void	build_buffer(char *buffer, int value, size_t buf_size)
{
	char	digit[2];

	if (value < 0)
	{
		ft_strlcat(buffer, "-", buf_size);
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
