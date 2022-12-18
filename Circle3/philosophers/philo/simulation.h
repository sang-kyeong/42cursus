/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:43:13 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 19:38:33 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>
# include "condition.h"
# include "fork.h"
# include "philo_info.h"

typedef struct s_simulation		t_simulation;

struct s_simulation
{
	struct timeval		start_time;
	size_t				progress;
	pthread_mutex_t		mutex_simulation;
	pthread_mutex_t		mutex_print;
	pthread_t			*thread_ids;
	t_condition			condition;
	t_fork				*forks;
	t_philo_info		*philo_infos;
};

#endif//SIMULATION_H
