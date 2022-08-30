/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:38:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 22:01:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	len;
	t_node	*top;
}	t_stack;

// stack1.c
int	init_stack(t_stack *stack);
int	clear_stack(t_stack *stack);
int	push_node(t_stack *stack, t_node *node);
int	pop_node(t_stack *stack, t_node **node_ptr);

// stack2.c
int	push_value(t_stack *stack, int value);
int	pop_value(t_stack *stack, int *value_ptr);
int	swap(t_stack *stack);
int	rotate(t_stack *stack);
int	reverse_rotate(t_stack *stack);

// stack3.c
int	to_array(t_stack *stack, int **arr_ptr);
int	is_sorted(t_stack *stack, size_t n);

#endif
