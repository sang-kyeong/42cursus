/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:52:43 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 15:35:54 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITION_H
# define CONDITION_H

# include <stddef.h>

typedef struct s_condition			t_condition;

struct s_condition
{
	long long				philo_num;
	long long				time_to_die;
	long long				time_to_eat;
	long long				time_to_sleep;
	long long				must_eat;
};

#endif//CONDITION_H
