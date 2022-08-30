/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:54:49 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 23:47:06 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	put_c(unsigned int c);
int	put_s(char *s);
int	put_p(void *p);
int	put_d(int d);
int	put_u(unsigned int u);
int	put_x(unsigned int x);
int	put_lx(unsigned int x);

int	valid_format(char specifier)
{
	if (specifier == 'c' || specifier == 's' || specifier == 'p'
		|| specifier == 'd' || specifier == 'i' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X' || specifier == '%')
		return (1);
	else
		return (0);
}

int	put_format(char specifier, va_list *ap)
{
	if (specifier == 'c')
		return (put_c(va_arg(*ap, int)));
	if (specifier == 's')
		return (put_s(va_arg(*ap, char *)));
	if (specifier == 'p')
		return (put_p(va_arg(*ap, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (put_d(va_arg(*ap, int)));
	if (specifier == 'u')
		return (put_u(va_arg(*ap, unsigned int)));
	if (specifier == 'x')
		return (put_x(va_arg(*ap, unsigned int)));
	if (specifier == 'X')
		return (put_lx(va_arg(*ap, unsigned int)));
	if (specifier == '%')
		return (put_c('%'));
	return (-1);
}

int	put_c(unsigned int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	put_s(char *s)
{
	size_t	len;

	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	len = ft_strlen(s);
	return (write(STDOUT_FILENO, s, len));
}
