/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:34:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 15:36:20 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "condition.h"
#include "error_code.h"

static int	parse_argument(unsigned int *uint_ptr, char *str);

int	get_condition(t_condition *condition, int argc, char *argv[])
{
	unsigned int	value;
	int				err;

	if (argc < 5 || argc > 6)
		return (INVALID_ARGUMENT);
	err = parse_argument(&value, argv[1]);
	condition->philo_num = (long long)value;
	if (err == 0)
		err = parse_argument(&value, argv[2]);
	condition->time_to_die = (long long)value;
	if (err == 0)
		err = parse_argument(&value, argv[3]);
	condition->time_to_eat = (long long)value;
	if (err == 0)
		err = parse_argument(&value, argv[4]);
	condition->time_to_sleep = (long long)value;
	if (err == 0 && argc == 6)
	{
		err = parse_argument(&value, argv[5]);
		condition->must_eat = (long long)value;
	}
	return (err);
}

static int	parse_argument(unsigned int *uint_ptr, char *str)
{
	size_t	value;

	value = 0;
	while ('0' <= *str && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		if (value > 0xFFFFFFFF)
			return (OUT_OF_RANGE);
		str++;
	}
	if ('\0' != *str)
		return (INVALID_ARGUMENT);
	if (value == 0)
		return (OUT_OF_RANGE);
	*uint_ptr = (unsigned int)value;
	return (SUCCESS);
}
