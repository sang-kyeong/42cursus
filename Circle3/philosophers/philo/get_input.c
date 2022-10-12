/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:46:04 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 16:35:10 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include "philo.h"

static int	init_sim(int argc, t_sim *sim);
static int	parse_input(char *argv[], t_sim *sim);

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
