/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:06:06 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/27 14:14:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "utils.h"

int		calc_direction(size_t pow, size_t i);
size_t	calc_amount(size_t pow, size_t i, size_t n);

void	merge_to_a(t_stack *a, t_stack *b, size_t pow, size_t n);
void	merge_to_b(t_stack *a, t_stack *b, size_t pow, size_t n);
void	make_triangle_a(t_stack *a, t_stack *b, int dir, size_t amt);
void	make_triangle_b(t_stack *a, t_stack *b, int dir, size_t amt);

void	merge_depth(t_stack *a, t_stack *b, size_t n, int depth)
{
	size_t	i;
	size_t	amt;
	size_t	pow;

	i = 0;
	amt = 0;
	pow = ft_pow(3, depth);
	while (i < pow)
		amt += calc_amount(pow * 3, 2 * pow + i++, n);
	if (depth % 2 == 0)
	{
		while (amt--)
			pa(a, b, 1);
		merge_to_a(a, b, pow, n);
	}
	else
	{
		while (amt--)
			pb(a, b, n);
		merge_to_b(a, b, pow, n);
	}
}

void	merge_to_a(t_stack *a, t_stack *b, size_t pow, size_t n)
{
	size_t	i;

	i = 0;
	while (i < pow)
	{
		make_triangle_a(a, b, calc_direction(pow, i), calc_amount(pow, i, n));
		i++;
	}
}

void	merge_to_b(t_stack *a, t_stack *b, size_t pow, size_t n)
{
	size_t	i;

	i = 0;
	while (i < pow)
	{
		make_triangle_b(a, b, calc_direction(pow, i), calc_amount(pow, i, n));
		i++;
	}
}

void	make_triangle_a(t_stack *a, t_stack *b, int dir, size_t amt)
{
	size_t	rest[3];

	rest[0] = amt / 3;
	rest[1] = amt / 3 + (amt % 3 > 0);
	rest[2] = amt / 3 + (amt % 3 > 1);
	while (rest[0] + rest[1] + rest[2])
	{
		if (rest[0]
			&& (!rest[1]
				|| (b->top->prev->value > b->top->value) == dir)
			&& (!rest[2]
				|| (b->top->prev->value > a->top->prev->value) == dir))
			rest[0] -= (rrb(a, b, 1) && pa(a, b, 1));
		else if (rest[1]
			&& (!rest[2]
				|| (b->top->value > a->top->prev->value) == dir))
			rest[1] -= pa(a, b, 1);
		else
			rest[2] -= rra(a, b, 1);
	}
}

void	make_triangle_b(t_stack *a, t_stack *b, int dir, size_t amt)
{
	size_t	rest[3];

	rest[0] = amt / 3;
	rest[1] = amt / 3 + (amt % 3 > 0);
	rest[2] = amt / 3 + (amt % 3 > 1);
	while (rest[0] + rest[1] + rest[2])
	{
		if (rest[0]
			&& (!rest[1]
				|| (a->top->prev->value > a->top->value) == dir)
			&& (!rest[2]
				|| (a->top->prev->value > b->top->prev->value) == dir))
			rest[0] -= (rra(a, b, 1) && pb(a, b, 1));
		else if (rest[1]
			&& (!rest[2]
				|| (a->top->value > b->top->prev->value) == dir))
			rest[1] -= pb(a, b, 1);
		else
			rest[2] -= rrb(a, b, 1);
	}
}
