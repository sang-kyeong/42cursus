/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:44:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 19:39:25 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stddef.h>
#include "condition.h"
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "util_time.h"
#include "error_code.h"

t_simulation_status			philo_echo_die(t_philo *philo);

static t_simulation_status	check_philo(t_philo *philo);
static t_simulation_status	check_full_philo(t_simulation *sim);

int	monitor_main(t_simulation *sim)
{
	t_simulation_status		sim_status;
	long long				i;

	sim_status = sim_running;
	wait_until_timeval(sim->start_time);
	while (sim_status == sim_running)
	{
		i = 0;
		while (i < sim->condition.philo_num && sim_status == sim_running)
		{
			sim_status = check_philo(&(sim->philos[i]));
			usleep(10);
			i++;
		}
		if (sim->type == sim_until_done && sim_status == sim_running)
			sim_status = check_full_philo(sim);
	}
	return (SUCCESS);
}

static t_simulation_status	check_philo(t_philo *philo)
{
	t_simulation_status	status;

	status = sim_running;
	pthread_mutex_lock(philo->mutex_philo_time);
	if (get_ms_from(philo->last_eat_time) >= philo->condition->time_to_die)
		status = philo_echo_die(philo);
	pthread_mutex_unlock(philo->mutex_philo_time);
	return (status);
}

static t_simulation_status	check_full_philo(t_simulation *sim)
{
	t_simulation_status	status;

	status = sim_running;
	pthread_mutex_lock(sim->mutex_sim_full_philo);
	if (sim->full_philo == sim->condition.philo_num)
	{
		pthread_mutex_lock(sim->mutex_sim_status);
		if (sim->status == sim_running)
			sim->status = sim_closing_done;
		status = sim->status;
		pthread_mutex_unlock(sim->mutex_sim_status);
	}
	pthread_mutex_unlock(sim->mutex_sim_full_philo);
	return (status);
}
