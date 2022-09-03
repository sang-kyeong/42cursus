/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/02 22:27:37 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIM_H
# define SIM_H

typedef struct s_sim		t_sim;
typedef enum e_sim_type		t_sim_type;

struct s_sim
{
	size_t				philo_num;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				time_to_think;
	t_sim_type			type;
	size_t				must_eat;
	pthread_mutex_t		mutex;
	struct timeval		start_time;
	size_t				progress;
};

enum e_sim_type
{
	until_die = 0,
	until_done,
};

#endif
