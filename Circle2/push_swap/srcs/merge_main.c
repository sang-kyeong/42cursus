/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:14:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:36:33 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int		tiny_sort(t_stack *a, t_stack *b);
void	init_depth(t_stack *a, t_stack *b, size_t n, int depth);
void	merge_depth(t_stack *a, t_stack *b, size_t n, int depth);

int		calc_depth(size_t n);

void	sort_stack(t_stack *a, t_stack *b)
{
	int		depth;
	size_t	n;

	if (is_sorted(a, a->len))
		return ;
	n = a->len;
	if (n <= 6)
		tiny_sort(a, b);
	else
	{
		depth = calc_depth(n);
		init_depth(a, b, n, depth);
		while (depth--)
			merge_depth(a, b, n, depth);
	}
}

int	calc_depth(size_t n)
{
	int	depth;

	depth = 0;
	while (n > 4)
	{
		n = n / 3 + (n % 3 > 0);
		depth++;
	}
	return (depth);
}

int	calc_direction(size_t pow, size_t i)
{
	if (pow == 1)
		return (1);
	else if (i < pow / 3)
		return (calc_direction(pow / 3, i));
	else if (i < 2 * pow / 3)
		return (!calc_direction(pow / 3, 2 * pow / 3 - 1 - i));
	else
		return (!calc_direction(pow / 3, pow - 1 - i));
}

size_t	calc_amount(size_t pow, size_t i, size_t n)
{
	size_t	tmp;

	if (pow == 1)
		return (n);
	else if (i < pow / 3)
	{
		tmp = calc_amount(pow / 3, i, n);
		return (tmp / 3);
	}
	else if (i < 2 * pow / 3)
	{
		tmp = calc_amount(pow / 3, 2 * pow / 3 - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 0));
	}
	else
	{
		tmp = calc_amount(pow / 3, pow - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 1));
	}
}
