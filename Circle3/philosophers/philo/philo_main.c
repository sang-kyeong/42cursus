/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 21:54:36 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "condition.h"
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "util_time.h"

t_simulation_status			philo_echo_take_fork(t_philo *philo);
t_simulation_status			philo_echo_eat(t_philo *philo);
t_simulation_status			philo_echo_sleep(t_philo *philo);
t_simulation_status			philo_echo_think(t_philo *philo);

t_simulation_status			philo_try_a_fork(t_philo *philo, \
	t_philo_hand *hand);
t_simulation_status			philo_wait_a_fork(t_philo *philo, \
	t_philo_hand *hand);
t_simulation_status			philo_wait_both_forks(t_philo *philo);
void						philo_put_down_a_fork(t_philo *philo, \
	t_philo_hand *hand);

static t_simulation_status	philo_take_first_fork(t_philo *philo);
static t_simulation_status	philo_eat(t_philo *philo);
static t_simulation_status	philo_sleep(t_philo *philo);
static t_simulation_status	philo_think(t_philo *philo);

#include <unistd.h>
void	*philo_main(void *arg)
{
	t_philo				*philo;
	t_simulation_status	sim_status;

write(1, "p", 1);
	philo = (t_philo *)arg;
	sim_status = sim_running;
	//wait_until_timeval(*(philo->sim_start_time));
	//philo_take_first_fork(philo);
	while (sim_status == sim_running)
	{
write(1, "p", 1);
		//sim_status = philo_eat(philo);
		//if (sim_status == sim_running)
		//	sim_status = philo_sleep(philo);
		//if (sim_status == sim_running)
		//	sim_status = philo_think(philo);
		//if (sim_status == sim_running)
		//	sim_status = philo_wait_both_forks(philo);
	}
	return (NULL);
}

static t_simulation_status	philo_take_first_fork(t_philo *philo)
{
	t_simulation_status	sim_status;

	if (philo->id % 2 == 1)
	{
		sim_status = philo_wait_a_fork(philo, &(philo->left_hand));
		if (sim_status == sim_running)
			sim_status = philo_wait_a_fork(philo, &(philo->right_hand));
	}
	else
	{
		sim_status = philo_wait_a_fork(philo, &(philo->right_hand));
		if (sim_status == sim_running)
			sim_status = philo_wait_a_fork(philo, &(philo->left_hand));
	}
	return (sim_status);
}

static t_simulation_status	philo_eat(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = philo_echo_eat(philo);
	if (sim_status == sim_running)
		wait_until_ms(philo->condition->time_to_eat);
	return (sim_status);
}

static t_simulation_status	philo_sleep(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = philo_echo_sleep(philo);
	philo->left_hand.status = hand_empty;
	pthread_mutex_lock(philo->left_hand.fork->mutex_fork);
	philo_put_down_a_fork(philo, &(philo->left_hand));
	philo_put_down_a_fork(philo, &(philo->right_hand));
	if (sim_status == sim_running)
		wait_until_ms(philo->condition->time_to_sleep);
	return (sim_status);
}

static t_simulation_status	philo_think(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = philo_echo_think(philo);
	return (sim_status);
}
