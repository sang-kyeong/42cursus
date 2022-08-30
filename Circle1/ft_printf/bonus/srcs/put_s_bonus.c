/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:19:30 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 19:18:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "format_bonus.h"

int	put_padding(char c, size_t len);

// 0	: Undefined
// .*	: max width of string
// *	: min width of output
// -	: right align with width
// +	: Undefined
// sp	: Undefined
// #	: Undefined

int	put_s(char *s, t_format format)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (format.f_precision && format.precision < slen)
	{
		slen = format.f_precision;
		s[slen] = '\0';
	}
	if (format.f_width && format.width > slen)
	{
		if (!format.f_minus)
			put_padding(' ', format.width - slen);
		write(1, s, ft_strlen(s));
		if (format.f_minus)
			put_padding(' ', format.width - slen);
		return (format.width);
	}
	write(1, s, ft_strlen(s));
	return (slen);
}
