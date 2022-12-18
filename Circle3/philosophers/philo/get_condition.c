/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:34:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 22:35:02 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "condition.h"
#include "error_code.h"

static int	parse_uint(unsigned int *uint_ptr, char *str);

int	get_condition(t_condition *condition, int argc, char *argv[])
{
	unsigned int	value;
	int				err;

	if (argc < 5 || argc > 6)
		return (INVALID_ARGUMENT);
	err = parse_uint(&value, argv[1]);
	condition->number_of_philosophers = (size_t)value;
	if (err == 0)
		err = parse_uint(&value, argv[2]);
	condition->time_to_die = (size_t)value;
	if (err == 0)
		err = parse_uint(&value, argv[3]);
	condition->time_to_eat = (size_t)value;
	if (err == 0)
		err = parse_uint(&value, argv[4]);
	condition->time_to_sleep = (size_t)value;
	if (err == 0)
	{
		err = parse_uint(&value, argv[5]);
		condition->philosopher_must_eat = (size_t)value;
		condition->simulation_mode = finite;
	}
	return (err);
}

static int	parse_uint(unsigned int *uint_ptr, char *str)
{
	size_t	value;

	value = 0;
	while ('0' <= *str && '9' >= *str)
	{
		value = value * 10 + (*str - '0');
		if (value > 0xFFFFFFFF)
			return (OUT_OF_RANGE);
		str++;
	}
	if ('\0' != *str)
		return (INVALID_ARGUMENT);
	*uint_ptr = (unsigned int)value;
	return (SUCCESS);
}
