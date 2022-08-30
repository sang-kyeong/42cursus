/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:34:54 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 21:55:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

char	*get_next_line(int fd);
int		parse_input(t_stack *stack, int argc, char **argv);

void	operate_push_swap(t_stack *a, t_stack *b);
int		operate(t_stack *a, t_stack *b, char *op);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	if (parse_input(&a, argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		clear_stack(&a);
		clear_stack(&a);
		return (0);
	}
	operate_push_swap(&a, &b);
	clear_stack(&a);
	clear_stack(&a);
	return (0);
}

void	operate_push_swap(t_stack *a, t_stack *b)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (operate(a, b, op) < 0)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(-1);
		}
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (b->len == 0 && is_sorted(a, a->len))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	operate(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", 4) == 0)
		return (sa(a, b, 0));
	else if (ft_strncmp(op, "sb\n", 4) == 0)
		return (sb(a, b, 0));
	else if (ft_strncmp(op, "ss\n", 4) == 0)
		return (ss(a, b, 0));
	else if (ft_strncmp(op, "pa\n", 4) == 0)
		return (pa(a, b, 0));
	else if (ft_strncmp(op, "pb\n", 4) == 0)
		return (pb(a, b, 0));
	else if (ft_strncmp(op, "ra\n", 4) == 0)
		return (ra(a, b, 0));
	else if (ft_strncmp(op, "rb\n", 4) == 0)
		return (rb(a, b, 0));
	else if (ft_strncmp(op, "rr\n", 4) == 0)
		return (rr(a, b, 0));
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		return (rra(a, b, 0));
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		return (rrb(a, b, 0));
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		return (rrr(a, b, 0));
	else
		return (-1);
}
