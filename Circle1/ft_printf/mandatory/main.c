/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:43:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 23:46:15 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	valid_format(char specifier);
int	put_format(char specifier, va_list *ap);

int	print_format(const char **format_string, va_list *ap);
int	print_string(const char **format_string);

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	int		tmp_printed;
	int		printed;

	va_start(ap, format_string);
	printed = 0;
	while (*format_string)
	{
		if (*format_string == '%')
			tmp_printed = print_format(&format_string, &ap);
		else
			tmp_printed = print_string(&format_string);
		if (tmp_printed < 0)
		{
			va_end(ap);
			return (-1);
		}
		else
			printed += tmp_printed;
	}
	va_end(ap);
	return (printed);
}

int	print_format(const char **format_string, va_list *ap)
{
	char	specifier;
	int		printed;

	(*format_string)++;
	specifier = **format_string;
	if (!valid_format(specifier))
		return (0);
	printed = put_format(specifier, ap);
	(*format_string)++;
	return (printed);
}

int	print_string(const char **format_string)
{
	size_t	len;
	int		printed;

	len = 0;
	while (*format_string[len] && *format_string[len] != '%')
		len++;
	printed = write(1, format_string, len);
	format_string += len;
	return (printed);
}
