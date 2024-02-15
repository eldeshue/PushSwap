/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:38 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/12 20:53:03 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

// check b empty.
// check a ordered.
int	is_ab_sorted(t_stack_ab *this)
{
	int	idx;

	idx = -1;
	if (b_size(this) != 0)
		return (0);
	while (++idx < this->size)
	{
		if (this->pdata[idx] != this->size - 1 - idx)
		{
			return (0);
		}
	}
	return (1);
}

int	a_size(t_stack_ab *this)
{
	return (this->pivot - this->a_bot);
}

int	b_size(t_stack_ab *this)
{
	return (this->b_bot - this->pivot - 1);
}
