/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:54:32 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 19:35:41 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

typedef enum e_fork_status			t_fork_status;
typedef struct s_fork				t_fork;

enum e_fork_status
{
	fork_available = 0,
	fork_unavailable,
};

struct s_fork
{
	pthread_mutex_t			*mutex_fork;
	t_fork_status			status;
};

#endif//FORK_H
