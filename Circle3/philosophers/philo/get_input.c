/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:46:04 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 13:32:11 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include "philo.h"

static int	init_sim(int argc, t_sim *sim);
static int	parse_input(char *argv[], t_sim *sim);
static void	calc_input(t_sim *sim);
static int	parse_uint(unsigned int *uint, char *s);

int	get_input(int argc, char *argv[], t_sim *sim)
{
	int		err;

	err = init_sim(argc, sim);
	if (err == 0)
		err = parse_input(argv, sim);
	if (err == 0)
		calc_input(sim);
	return (err);
}

static int	init_sim(int argc, t_sim *sim)
{
	if (argc < 5 || 6 < argc)
		return (ERR_INVALID_INPUT);
	memset(sim, 0, sizeof(t_sim));
	if (argc == 5)
		sim->info.type = until_die;
	else
		sim->info.type = until_done;
	return (0);
}

static int	parse_input(char *argv[], t_sim *sim)
{
	int		err;

	err = parse_uint((unsigned int *)&(sim->info.philo_num), argv[1]);
	if (err == 0 && sim->info.philo_num == 0)
		err = ERR_INVALID_INPUT;
	if (err == 0)
		err = parse_uint((unsigned int *)&(sim->info.time_to_die), argv[2]);
	if (err == 0)
		err = parse_uint((unsigned int *)&(sim->info.time_to_eat), argv[3]);
	if (err == 0)
		err = parse_uint((unsigned int *)&(sim->info.time_to_sleep), argv[4]);
	if (err == 0 && sim->info.type == until_done)
		err = parse_uint((unsigned int *)&(sim->info.must_eat), argv[5]);
	if (err == 0 && sim->info.type == until_done && sim->info.must_eat == 0)
		err = ERR_INVALID_INPUT;
	return (err);
}

static void	calc_input(t_sim *sim)
{
	size_t	period;
	size_t	n;

	n = sim->info.philo_num / 2;
	period = (sim->info.time_to_eat * sim->info.philo_num) / n;
	period += ((sim->info.time_to_eat * sim->info.philo_num) % n) > 0;
	sim->info.time_to_think = period - sim->info.time_to_eat - sim->info.time_to_sleep;
}

static int	parse_uint(unsigned int *uint, char *s)
{
	size_t	val;

	if (*s < '0' || '9' < *s)
		return (-1);
	val = 0;
	while ('0' <= *s && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		if (val > UINT_MAX)
			return (ERR_INVALID_INPUT);
		s++;
	}
	if (*s)
		return (ERR_INVALID_INPUT);
	*uint = val;
	return (0);
}
