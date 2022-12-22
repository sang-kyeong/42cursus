/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/22 16:13:20 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "util_time.h"

t_simulation_status	check_philo(t_philo *philo);

t_simulation_status	philo_echo_take_fork(t_philo *philo)
{
	t_simulation_status	sim_status;

	pthread_mutex_lock(philo->mutex_sim_status);
	sim_status = *(philo->sim_status);
	if (sim_status == sim_running)
	{
		printf("%lld %lld has taken a fork\n", \
			get_ms_from(*(philo->sim_start_time)), philo->id);
	}
	pthread_mutex_unlock(philo->mutex_sim_status);
	return (sim_status);
}

t_simulation_status	philo_echo_eat(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = check_philo(philo);
	if (sim_status != sim_running)
		return (sim_status);
	pthread_mutex_lock(philo->mutex_philo_time);
	gettimeofday(&(philo->last_eat_time), NULL);
	pthread_mutex_unlock(philo->mutex_philo_time);
	pthread_mutex_lock(philo->mutex_sim_status);
	if (*(philo->sim_status) == sim_running)
	{
		if (sim_status == sim_closing_died)
			*(philo->sim_status) = sim_closing_died;
		else
			printf("%lld %lld is eating\n", \
				get_ms_from(*(philo->sim_start_time)), philo->id);
	}
	sim_status = *(philo->sim_status);
	pthread_mutex_unlock(philo->mutex_sim_status);
	return (sim_status);
}

t_simulation_status	philo_echo_sleep(t_philo *philo)
{
	t_simulation_status	sim_status;

	if (++(philo->eat_cnt) == philo->sim_condition->must_eat)
	{
		pthread_mutex_lock(philo->mutex_sim_full_philo);
		if (++*(philo->sim_full_philo) == philo->sim_condition->philo_num)
		{
			pthread_mutex_lock(philo->mutex_sim_status);
			if (*(philo->sim_status) == sim_running)
				*(philo->sim_status) = sim_closing_done;
			pthread_mutex_unlock(philo->mutex_sim_status);
		}
		pthread_mutex_unlock(philo->mutex_sim_full_philo);
	}
	pthread_mutex_lock(philo->mutex_sim_status);
	sim_status = *(philo->sim_status);
	if (sim_status == sim_running)
	{
		printf("%lld %lld is sleeping\n", \
			get_ms_from(*(philo->sim_start_time)), philo->id);
	}
	pthread_mutex_unlock(philo->mutex_sim_status);
	return (sim_status);
}

t_simulation_status	philo_echo_think(t_philo *philo)
{
	t_simulation_status	sim_status;

	pthread_mutex_lock(philo->mutex_sim_status);
	sim_status = *(philo->sim_status);
	if (sim_status == sim_running)
		printf("%lld %lld is thinking\n", \
			get_ms_from(*(philo->sim_start_time)), philo->id);
	pthread_mutex_unlock(philo->mutex_sim_status);
	return (sim_status);
}

t_simulation_status	philo_echo_die(t_philo *philo)
{
	t_simulation_status	sim_status;

	pthread_mutex_lock(philo->mutex_sim_status);
	if (*(philo->sim_status) == sim_running)
	{
		printf("%lld %lld died\n", \
			get_ms_from(*(philo->sim_start_time)), philo->id);
		*(philo->sim_status) = sim_closing_died;
	}
	sim_status = *(philo->sim_status);
	pthread_mutex_unlock(philo->mutex_sim_status);
	return (sim_status);
}
