/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:45:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:20:22 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

int	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	push_node(stack, node);
	return (1);
}

int	pop_value(t_stack *stack, int *value_ptr)
{
	t_node	*node;

	*value_ptr = 0;
	if (pop_node(stack, &node))
	{
		*value_ptr = node->value;
		free(node);
		return (1);
	}
	else
		return (0);
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return (1);
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	return (1);
}

int	rotate(t_stack *stack)
{
	if (stack->len >= 2)
		stack->top = stack->top->next;
	return (1);
}

int	reverse_rotate(t_stack *stack)
{
	if (stack->len >= 2)
		stack->top = stack->top->prev;
	return (1);
}
