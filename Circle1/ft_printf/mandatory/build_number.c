/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:20:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 23:35:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	build_deci(char *buffer, ssize_t value, size_t buffer_size)
{
	ssize_t	upper;
	ssize_t	lower;
	char	digit[2];

	upper = value / 10;
	lower = value % 10;
	if (value < 0)
	{
		ft_strlcat(buffer, "-", buffer_size);
		upper *= -1;
		lower *= -1;
	}
	if (upper)
		build_deci(buffer, upper, buffer_size);
	digit[0] = ("0123456789")[lower];
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buffer_size);
}

void	build_hex(char *buffer, size_t value)
{
	ssize_t	upper;
	ssize_t	lower;
	char	digit[2];

	upper = value / 16;
	lower = value % 16;
	if (upper)
		build_hex(buffer, upper, buffer_size);
	digit[0] = ("0123456789abcdef")[lower];
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buffer_size);
}

void	build_lhex(char *buffer, size_t value)
{
	ssize_t	upper;
	ssize_t	lower;
	char	digit[2];

	upper = value / 16;
	lower = value % 16;
	if (upper)
		build_hex(buffer, upper, buffer_size);
	digit[0] = ("0123456789ABCDEF")[lower];
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buffer_size);
}
