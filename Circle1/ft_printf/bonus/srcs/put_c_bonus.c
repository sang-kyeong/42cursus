/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:17:17 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 23:43:26 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "format_bonus.h"

int	put_padding(char c, size_t len);

// 0	: Undefined
// .*	: Undefined
// *	: min width of output
// -	: right align with width
// +	: Undefined
// sp	: Undefined
// #	: Undefined
int	put_c(unsigned char c, t_format format)
{
	if (format.f_width)
	{
		if (!format.f_minus)
			put_padding(' ', format.width - 1);
		write(1, &c, 1);
		if (format.f_minus)
			put_padding(' ', format.width - 1);
		return (format.width);
	}
	write(1, &c, 1);
	return (1);
}
