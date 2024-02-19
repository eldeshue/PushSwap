/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_query_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:00:09 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/19 14:10:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "stack_ab_bonus.h"

// query selector
// take string as an input and manipulate ab
// return 0 if failed.
int	select_query(t_stack_ab *this, const char *query, const int query_size)
{
	if (ft_strncmp(query, "pa", query_size) == 0 && query_size == 2)
		pa(this);
	else if (ft_strncmp(query, "pb", query_size) == 0 && query_size == 2)
		pb(this);
	else if (ft_strncmp(query, "sa", query_size) == 0 && query_size == 2)
		sa(this);
	else if (ft_strncmp(query, "sb", query_size) == 0 && query_size == 2)
		sb(this);
	else if (ft_strncmp(query, "ss", query_size) == 0 && query_size == 2)
		ss(this);
	else if (ft_strncmp(query, "ra", query_size) == 0 && query_size == 2)
		ra(this);
	else if (ft_strncmp(query, "rb", query_size) == 0 && query_size == 2)
		rb(this);
	else if (ft_strncmp(query, "rr", query_size) == 0 && query_size == 2)
		rr(this);
	else if (ft_strncmp(query, "rra", query_size) == 0 && query_size == 3)
		rra(this);
	else if (ft_strncmp(query, "rrb", query_size) == 0 && query_size == 3)
		rrb(this);
	else if (ft_strncmp(query, "rrr", query_size) == 0 && query_size == 3)
		rrr(this);
	else
		return (0);
	return (1);
}
