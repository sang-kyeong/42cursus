/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:12:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:32:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# include "stack.h"

// push_swap1.c
int	sa(t_stack *a, t_stack *b, int print);
int	sb(t_stack *a, t_stack *b, int print);
int	ss(t_stack *a, t_stack *b, int print);
int	pa(t_stack *a, t_stack *b, int print);
int	pb(t_stack *a, t_stack *b, int print);

// push_swap2.c
int	ra(t_stack *a, t_stack *b, int print);
int	rb(t_stack *a, t_stack *b, int print);
int	rr(t_stack *a, t_stack *b, int print);

// push_swap3.c
int	rra(t_stack *a, t_stack *b, int print);
int	rrb(t_stack *a, t_stack *b, int print);
int	rrr(t_stack *a, t_stack *b, int print);

#endif