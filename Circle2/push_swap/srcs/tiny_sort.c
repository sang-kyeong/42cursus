/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:21:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:32:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	tiny_sort_a(t_stack *a, t_stack *b);
int	tiny_rev_sort_b(t_stack *a, t_stack *b);
int	tiny_merge(t_stack *a, t_stack *b);

int	tiny_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if (a->len <= 3)
		return (tiny_sort_a(a, b));
	else if (a->len <= 6)
	{
		i = a->len - 3;
		while (i--)
			pb(a, b, 1);
		tiny_sort_a(a, b);
		tiny_rev_sort_b(a, b);
		tiny_merge(a, b);
		return (1);
	}
	else
		return (-1);
}

int	tiny_sort_a(t_stack *a, t_stack *b)
{
	if (a->len <= 1)
		return (1);
	else if (a->len == 2)
		return (a->top->value < a->top->next->value || sa(a, b, 1));
	else if (a->len == 3)
	{
		if (a->top->value > a->top->next->value
			&& a->top->value > a->top->prev->value)
			ra(a, b, 1);
		else if (a->top->next->value > a->top->prev->value)
			rra(a, b, 1);
		if (a->top->value > a->top->next->value)
			sa(a, b, 1);
		return (1);
	}
	else
		return (0);
}

int	tiny_rev_sort_b(t_stack *a, t_stack *b)
{
	if (b->len <= 1)
		return (1);
	else if (b->len == 2)
		return (b->top->value > b->top->next->value || sb(a, b, 1));
	else if (b->len == 3)
	{
		if (b->top->value < b->top->next->value
			&& b->top->value < b->top->prev->value)
			rb(a, b, 1);
		else if (b->top->next->value < b->top->prev->value)
			rrb(a, b, 1);
		if (b->top->value < b->top->next->value)
			sb(a, b, 1);
		return (1);
	}
	else
		return (0);
}

int	tiny_merge(t_stack *a, t_stack *b)
{
	size_t	rest[2];

	rest[0] = a->len;
	rest[1] = b->len;
	while (rest[0] + rest[1])
	{
		if (!rest[1])
			rest[0] -= rra(a, b, 1);
		else if (!rest[0])
			rest[1] -= pa(a, b, 1);
		else if (a->top->prev->value > b->top->value)
			rest[0] -= rra(a, b, 1);
		else
			rest[1] -= pa(a, b, 1);
	}
	return (1);
}
