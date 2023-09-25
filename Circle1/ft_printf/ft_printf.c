/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:27:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 16:23:04 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char **f_string, va_list *ap);
int	print_string(const char **f_string);

int	put_character(char c);
int	put_string(char *s);
int	put_pointer(void *ptr);
int	put_decimal(long value);
int	put_hex(unsigned int value, char hex_case);

int	ft_printf(const char *f_string, ...)
{
	int		total_len;
	int		temp_len;
	va_list	ap;

	total_len = 0;
	va_start(ap, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
			temp_len = print_format(&f_string, &ap);
		else
			temp_len = print_string(&f_string);
		if (temp_len < 0)
		{
			total_len = -1;
			break ;
		}
		total_len += temp_len;
	}
	va_end(ap);
	return (total_len);
}

int	print_format(const char **f_string, va_list *ap)
{
	char	specifier;

	*f_string += 1;
	if (!**f_string)
		return (0);
	specifier = **f_string;
	*f_string += 1;
	if (specifier == 'c')
		return (put_character(va_arg(*ap, int)));
	else if (specifier == 's')
		return (put_string(va_arg(*ap, char *)));
	else if (specifier == 'p')
		return (put_pointer(va_arg(*ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (put_decimal(va_arg(*ap, int)));
	else if (specifier == 'u')
		return (put_decimal(va_arg(*ap, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (put_hex(va_arg(*ap, unsigned int), specifier));
	else
		return (put_character(specifier));
}

int	print_string(const char **f_string)
{
	char	*start;

	start = (char *)(*f_string);
	while (**f_string && **f_string != '%')
		*f_string += 1;
	return (write(1, start, *f_string - start));
}
