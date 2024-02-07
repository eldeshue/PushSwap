/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_ab_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:00:38 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/07 14:37:47 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab_bonus.h"

// check b empty.
// check a ordered.
int	is_ab_sorted(t_stack_ab *this)
{
	int			idx;

	idx = -1;
	if (this->pivot != this->size)
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
