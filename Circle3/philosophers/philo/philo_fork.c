/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:41:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 21:14:59 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "error_code.h"

t_simulation_status	philo_echo_take_fork(t_philo *philo);

t_simulation_status	philo_try_a_fork(t_philo *philo, t_philo_hand *hand)
{
	t_simulation_status	sim_status;

	pthread_mutex_lock(hand->fork->mutex_fork);
	if (hand->fork->status == fork_available)
	{
		hand->fork->status = fork_unavailable;
		hand->status = hand_holding;
		sim_status = philo_echo_take_fork(philo);
	}
	else
		sim_status = sim_running;
	pthread_mutex_unlock(hand->fork->mutex_fork);
	return (sim_status);
}

t_simulation_status	philo_wait_a_fork(t_philo *philo, t_philo_hand *hand)
{
	t_simulation_status	sim_status;

	while (hand->status == hand_empty)
	{
		sim_status = philo_try_a_fork(philo, hand);
		usleep(100);
	}
	return (sim_status);
}

t_simulation_status	philo_wait_both_forks(t_philo *philo)
{
	t_simulation_status	sim_status;

	sim_status = sim_running;
	while (philo->left_hand.status == hand_empty \
		|| philo->right_hand.status == hand_empty)
	{
		if (philo->left_hand.status == hand_empty)
			sim_status = philo_try_a_fork(philo, &(philo->left_hand));
		if (sim_status != sim_running)
			break ;
		if (philo->right_hand.status == hand_empty)
			sim_status = philo_try_a_fork(philo, &(philo->right_hand));
		if (sim_status != sim_running)
			break ;
	}
	return (sim_status);
}

void	philo_put_down_a_fork(t_philo *philo, t_philo_hand *hand)
{
	(void)philo;
	if (hand->status == hand_empty)
		return ;
	pthread_mutex_lock(hand->fork->mutex_fork);
	hand->fork->status = fork_available;
	pthread_mutex_unlock(hand->fork->mutex_fork);
	hand->status = hand_empty;
}
