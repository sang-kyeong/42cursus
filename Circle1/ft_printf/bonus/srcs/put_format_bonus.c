/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:31:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 23:39:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "format_bonus.h"

int	put_c(unsigned char c, t_format format);
int	put_s(char *s, t_format format);
int	put_p(void *p, t_format format);
int	put_d(int d, t_format format);
int	put_u(unsigned int u, t_format format);
int	put_x(unsigned int x, t_format format);

int	put_format(t_format format , va_list *ap)
{
	if (format.specifier == 'c')
		return (put_c((unsigned char)va_arg(*ap, unsigned int), format));
	else if (format.specifier == 's')
		return (put_s(va_arg(*ap, char *), format));
	else if (format.specifier == 'p')
		return (put_p(va_arg(*ap, void *), format));
	else if (format.specifier == 'd' || format.specifier == 'i')
		return (put_d(va_arg(*ap, int), format));
	else if (format.specifier == 'u')
		return (put_u(va_arg(*ap, unsigned int), format));
	else if (format.specifier == 'x' || format.specifier == 'X')
		return (put_x(va_arg(*ap, unsigned int), format));
	else if (format.specifier == '%')
		return (put_c('%', format));
	else
		return(-1);
}