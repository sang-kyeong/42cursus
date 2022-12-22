/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/22 16:10:46 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "util_time.h"

t_simulation_status			philo_echo_take_fork(t_philo *philo);
t_simulation_status			philo_echo_eat(t_philo *philo);
t_simulation_status			philo_echo_sleep(t_philo *philo);
t_simulation_status			philo_echo_think(t_philo *philo);

static t_simulation_status	philo_take_forks(t_philo *philo);
static t_simulation_status	philo_eat(t_philo *philo);
static t_simulation_status	philo_sleep(t_philo *philo);
static void					philo_put_down_forks(t_philo *philo);

void	*philo_main(void *arg)
{
	t_philo				*philo;
	t_simulation_status	sim_status;

	philo = (t_philo *)arg;
	sim_status = sim_running;
	wait_until_timeval(*(philo->sim_start_time));
	if (philo->id % 2 == 1)
		wait_until_ms(philo->sim_condition->time_to_eat / 2);
	while (sim_status == sim_running)
	{
		sim_status = philo_take_forks(philo);
		if (sim_status == sim_running)
			sim_status = philo_eat(philo);
		if (sim_status == sim_running)
			sim_status = philo_sleep(philo);
		if (sim_status == sim_running)
			sim_status = philo_echo_think(philo);
	}
	philo_put_down_forks(philo);
	return (NULL);
}

static t_simulation_status	philo_take_forks(t_philo *philo)
{
	t_simulation_status	sim_status;

	pthread_mutex_lock(philo->left_hand.fork->mutex_fork);
	philo->left_hand.fork->status = fork_unavailable;
	philo->left_hand.status = hand_holding;
	sim_status = philo_echo_take_fork(philo);
	if (sim_status != sim_running)
		return (sim_status);
	pthread_mutex_lock(philo->right_hand.fork->mutex_fork);
	philo->right_hand.fork->status = fork_unavailable;
	philo->right_hand.status = hand_holding;
	sim_status = philo_echo_take_fork(philo);
	return (sim_status);
}

static t_simulation_status	philo_eat(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = philo_echo_eat(philo);
	if (sim_status == sim_running)
		wait_until_ms(philo->sim_condition->time_to_eat);
	return (sim_status);
}

static t_simulation_status	philo_sleep(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = philo_echo_sleep(philo);
	pthread_mutex_unlock(philo->left_hand.fork->mutex_fork);
	philo->left_hand.fork->status = fork_available;
	philo->left_hand.status = hand_empty;
	pthread_mutex_unlock(philo->right_hand.fork->mutex_fork);
	philo->right_hand.fork->status = fork_available;
	philo->right_hand.status = hand_empty;
	if (sim_status == sim_running)
		wait_until_ms(philo->sim_condition->time_to_sleep);
	return (sim_status);
}

static void	philo_put_down_forks(t_philo *philo)
{
	if (philo->left_hand.status == hand_holding)
	{
		pthread_mutex_unlock(philo->left_hand.fork->mutex_fork);
		philo->left_hand.fork->status = fork_available;
		philo->left_hand.status = hand_empty;
	}
	if (philo->right_hand.status == hand_holding)
	{
		pthread_mutex_unlock(philo->right_hand.fork->mutex_fork);
		philo->right_hand.fork->status = fork_available;
		philo->right_hand.status = hand_empty;
	}
}
