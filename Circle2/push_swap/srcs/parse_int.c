/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:04:12 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 22:20:37 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char	*parse_hex(long long *value, char *str);
char	*parse_octal(long long *value, char *str);
char	*parse_binary(long long *value, char *str);
char	*parse_decimal(long long *value, char *str);

char	*parse_int(int *value, char *str)
{
	long long	tmp_value;
	char		*next_s;

	if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "-0x", 3)
		|| !ft_strncmp(str, "+0x", 3))
		next_s = parse_hex(&tmp_value, str);
	else if (!ft_strncmp(str, "0b", 2) || !ft_strncmp(str, "-0b", 3)
		|| !ft_strncmp(str, "+0b", 3))
		next_s = parse_binary(&tmp_value, str);
	else if (!ft_strncmp(str, "0", 1) || !ft_strncmp(str, "-0", 2)
		|| !ft_strncmp(str, "+0", 2))
		next_s = parse_octal(&tmp_value, str);
	else
		next_s = parse_decimal(&tmp_value, str);
	if (tmp_value < INT_MIN)
		*value = INT_MIN;
	else if (tmp_value > INT_MAX)
		*value = INT_MAX;
	else
		*value = (int)tmp_value;
	return (next_s);
}

char	*parse_hex(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	if (!('0' <= *str && *str <= '9') && !('A' <= *str && *str <= 'F')
		&& !('a' <= *str && *str <= 'f'))
		return (NULL);
	*value = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			*value = *value * 16 + sign * (*str - '0');
		else if ('A' <= *str && *str <= 'F')
			*value = *value * 16 + sign * (*str - 'A' + 10);
		else if ('a' <= *str && *str <= 'f')
			*value = *value * 16 + sign * (*str - 'a' + 10);
		else
			break ;
		if (*value < INT_MIN || *value > INT_MAX)
			return (NULL);
		str++;
	}
	return (str);
}

char	*parse_octal(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	*value = 0;
	while ('0' <= *str && *str <= '7')
	{
		*value = *value * 8 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (NULL);
		str++;
	}
	return (str);
}

char	*parse_binary(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	str += 2;
	if (*str < '0' || '1' < *str)
		return (NULL);
	*value = 0;
	while ('0' <= *str && *str <= '1')
	{
		*value = *value * 2 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (NULL);
		str++;
	}
	return (str);
}

char	*parse_decimal(long long *value, char *str)
{
	long long	sign;

	sign = 1 - 2 * (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' || '9' < *str)
		return (NULL);
	*value = 0;
	while ('0' <= *str && *str <= '9')
	{
		*value = *value * 10 + sign * (*str - '0');
		if (*value < INT_MIN || *value > INT_MAX)
			return (NULL);
		str++;
	}
	return (str);
}
