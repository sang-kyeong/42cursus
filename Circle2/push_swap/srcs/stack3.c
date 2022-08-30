/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:56:32 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:06:50 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

int	to_array(t_stack *stack, int **arr_ptr)
{
	size_t	i;
	t_node	*node;
	int		*arr;

	arr = malloc(stack->len * sizeof(int));
	if (arr == NULL)
		return (0);
	node = stack->top;
	i = 0;
	while (i < stack->len)
	{
		arr[i] = node->value;
		i++;
		node = node->next;
	}
	*arr_ptr = arr;
	return (1);
}

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (n > stack->len)
		n = stack->len;
	node = stack->top;
	while (--n)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
