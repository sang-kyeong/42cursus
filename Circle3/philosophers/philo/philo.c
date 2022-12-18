/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:32:43 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 22:48:16 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "simulation.h"
#include "error_code.h"

int	get_condition(t_condition *condition, int argc, char *argv[]);
int	init_simulation(t_simulation *simulation);
int	run_simulation(t_simulation *simulation);
int	monitor_main(t_simulation *simulation);

int	main(int argc, char *argv[])
{
	int				err;
	t_simulation	simulation;

	memset(&simulation, 0, sizeof(t_simulation));
	err = get_condition(&(simulation.condition), argc, argv);
	if (err == SUCCESS)
		init_simulation(&simulation);
	if (err == SUCCESS)
		err = run_simulation(&simulation);
	if (err == SUCCESS)
		err = monitor_main(&simulation);
	// if (err == SUCCESS)
	// 	err = terminate_simulation(&simulation);
	return (err);
}

int	run_simulation(t_simulation *simulation)
{
	gettimeofday(&(simulation->start_time), NULL);
	pthread_mutex_unlock(&(simulation->mutex_simulation));
	return (0);
}

