/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:37:47 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 22:19:02 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INFO_H
# define PHILO_INFO_H

# include <stddef.h>
# include <pthread.h>
# include "condition.h"
# include "fork.h"

typedef enum e_hand				t_hand;
typedef struct s_philo_info		t_philo_info;

enum e_hand
{
	empty = 0,
	holding,
};

struct s_philo_info
{
	size_t				id;
	size_t				deadline;
	size_t				eat_cnt;
	t_fork				*right_fork;
	t_hand				right_hand;
	t_fork				*left_fork;
	t_hand				left_hand;
	pthread_mutex_t		*mutex_simulation;
	pthread_mutex_t		*mutex_print;
	size_t				*simulation_progress;
	t_condition			*simulation_condition;
};

#endif//PHILO_INFO_H
