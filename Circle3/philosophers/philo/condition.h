/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:42:25 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 19:38:14 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITION_H
# define CONDITION_H

# include <stddef.h>

typedef enum e_simulation_mode	t_simulation_mode;
typedef struct s_condition		t_condition;

enum e_simulation_mode
{
	infinite = 0,
	finite,
};

struct s_condition
{
	size_t				number_of_philosophers;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	t_simulation_mode	simulation_mode;
	size_t				philosopher_must_eat;
};

#endif//CONDITION_H
