/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:15:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/11 00:31:05 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "format_bonus.h"

void			get_format(t_format *format, char **str);
int				check_format(t_format format);
int				put_format(t_format format, va_list *ap);

static int		print_format(char **str_p, va_list *ap);
static int		print_string(char **str_p);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			printed += print_format((char **)&str, &ap);
		else
			printed += print_string((char **)&str);
	}
	va_end(ap);
	return (printed);
}

static int	print_format(char **str_p, va_list *ap)
{
	t_format	format;
	int			printed;

	get_format(&format, str_p);
	if (check_format(format) < 0)
		return (-1);
	printed = put_format(format, ap);
	return (printed);
}

static int	print_string(char **str_p)
{
	int	len;
	int	printed;

	len = 0;
	while ((*str_p)[len] && (*str_p)[len] != '%')
		len++;
	printed = (int)write(1, *str_p, len);
	*str_p += len;
	return (printed);
}
