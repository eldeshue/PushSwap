/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_quick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:41:54 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/15 17:22:52 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

void	do_cmd(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int cmd)
{
	if (cmd == PA)
		pa(pab);
	else if (cmd == PB)
		pb(pab);
	else if (cmd == RA)
		ra(pab);
	else if (cmd == RB)
		rb(pab);
	else if (cmd == RR)
		rr(pab);
	else if (cmd == RRA)
		rra(pab);
	else if (cmd == RRB)
		rrb(pab);
	else if (cmd == RRR)
		rrr(pab);
	else if (cmd == SA)
		sa(pab);
	else if (cmd == SB)
		sb(pab);
	else if (cmd == SS)
		ss(pab);
	p_cmd_vec->push_back(p_cmd_vec, &cmd);
}

// half open, end not included, O(5 * N / 3)
/*
			||
			||					||
	a_bot	||	a_top . b_top	||||	b_bot
*/
static void	split_a3(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start,
		int end)
{
	const int	partition_size = (end - start) / 3;
	const int	big_pivot = end - partition_size;
	const int	small_pivot = big_pivot - partition_size;
	int			idx;

	idx = -1;
	while (++idx < end - start)
	{
		if (big_pivot <= a_top(pab) && a_top(pab) < end)
			do_cmd(pab, p_cmd_vec, RA);
		else if (small_pivot <= a_top(pab) && a_top(pab) < big_pivot)
		{
			do_cmd(pab, p_cmd_vec, PB);
			do_cmd(pab, p_cmd_vec, RB);
		}
		else
			do_cmd(pab, p_cmd_vec, PB);
	}
	idx = -1;
	while (++idx < partition_size)
		do_cmd(pab, p_cmd_vec, RRR);
}

void	quick_a(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end)
{
	const int	partition_size = (end - start) / 3;
	const int	big_pivot = end - partition_size;
	const int	small_pivot = big_pivot - partition_size;
	int			idx;

	if (partition_size == 0)
		sort_base_case(pab, p_cmd_vec, end - start);
	else
	{
		split_a3(pab, p_cmd_vec, start, end);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, big_pivot, end);
		idx = -1;
		while (++idx < partition_size)
			do_cmd(pab, p_cmd_vec, PA);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, small_pivot, big_pivot);
		idx = -1;
		while (++idx < (end - start) - 2 * partition_size)
			do_cmd(pab, p_cmd_vec, PA);
		if (!is_a_sorted_n(pab, (end - start) - 2 * partition_size))
			quick_a(pab, p_cmd_vec, start, small_pivot);
	}
}

// split first
static void	split_first(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start,
		int end)
{
	const int	partition_size = (end - start) / 3;
	const int	big_pivot = end - partition_size;
	const int	small_pivot = big_pivot - partition_size;
	int			idx;

	idx = -1;
	while (++idx < end - start)
	{
		if (big_pivot <= a_top(pab) && a_top(pab) < end)
			do_cmd(pab, p_cmd_vec, RA);
		else if (start <= a_top(pab) && a_top(pab) < small_pivot)
		{
			do_cmd(pab, p_cmd_vec, PB);
			do_cmd(pab, p_cmd_vec, RB);
		}
		else
			do_cmd(pab, p_cmd_vec, PB);
	}
}

void	sort_ab(t_stack_ab *pab, t_ft_vector *p_cmd_vec)
{
	const int	partition_size = pab->size / 3;
	const int	big_pivot = pab->size - partition_size;
	const int	small_pivot = big_pivot - partition_size;
	int			idx;

	if (partition_size == 0)
		sort_base_case(pab, p_cmd_vec, pab->size);
	else
	{
		split_first(pab, p_cmd_vec, 0, pab->size);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, big_pivot, pab->size);
		idx = -1;
		while (++idx < partition_size)
			do_cmd(pab, p_cmd_vec, PA);
		if (!is_a_sorted_n(pab, partition_size))
			quick_a(pab, p_cmd_vec, small_pivot, big_pivot);
		idx = -1;
		while (++idx < pab->size - 2 * partition_size)
			do_cmd(pab, p_cmd_vec, PA);
		if (!is_a_sorted_n(pab, pab->size - 2 * partition_size))
			quick_a(pab, p_cmd_vec, 0, small_pivot);
	}
}
