/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:45:55 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/11 00:30:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
#include "format_bonus.h"

#include <unistd.h>

static void	set_flags(t_format *format, char c);
static void	set_precision(t_format *format, char **s);
static void	set_width(t_format *format, char **s);

void	get_format(t_format *format, char **str)
{
	ft_bzero(format, sizeof(t_format));
	*str += 1;
	while (**str)
	{
		if (ft_strchr("-0# +", **str))
			set_flags(format, *(*str++));
		else if (**str == '.')
			set_precision(format, str);
		else if (ft_isdigit(**str))
			set_width(format, str);
		else
		{
			format->specifier = *(*str);
			break ;
		}
	}
	if (**str)
		*str += 1;
}

static void	set_flags(t_format *format, char c)
{
	if (c == '-')
		format->f_minus = 1;
	else if (c == '0')
		format->f_zero = 1;
	else if (c == '#')
		format->f_hash = 1;
	else if (c == ' ')
		format->f_space = 1;
	else if (c == '+')
		format->f_plus = 1;
}

static void	set_precision(t_format *format, char **s)
{
	size_t	value;

	format->f_precision = 1;
	*s += 1;
	value = 0;
	while (ft_isdigit(**s))
	{
		if (value < INT_MAX)
			value = value * 10 + **s - '0';
		*s += 1;
	}
	format->precision = value;
}

static void	set_width(t_format *format, char **s)
{
	size_t	value;

	format->f_width = 1;
	value = 0;
	while (ft_isdigit(**s))
	{
		if (value < INT_MAX)
			value = value * 10 + **s - '0';
		*s += 1;
	}
	format->width = value;
}
