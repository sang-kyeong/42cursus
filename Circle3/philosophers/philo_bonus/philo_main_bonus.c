/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:29:38 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/18 16:52:26 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_main_bonus(t_sim sim)
{
	t_philo	philo;
	size_t	time;

	while (philo.status != died)
	{
		sem_wait(sim.mutex);
		time = get_ms_from(sim.start_time);
		philo_action(&philo, time);
		sem_wait(sim.mutex);
		usleep(10);
	}
	return (0);
}
