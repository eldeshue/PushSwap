/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:22:06 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/09 16:39:34 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab_bonus.h"

void ra(t_stack_ab *this)
{
	int idx;
	int tmp;

	if (a_size(this) <= 0)
		return;
	idx = this->pivot - 1;
	tmp = this->pdata[idx];
	while (idx > this->a_bot)
	{
		this->pdata[idx] = this->pdata[idx - 1];
		idx--;
	}
	this->pdata[this->a_bot] = tmp;
}

void rb(t_stack_ab *this)
{
	int idx;
	int tmp;

	if (b_size(this) <= 0)
		return;
	idx = this->pivot;
	tmp = this->pdata[idx];
	while (idx < this->b_bot)
	{
		this->pdata[idx] = this->pdata[idx + 1];
		idx++;
	}
	this->pdata[this->b_bot] = tmp;
}

void rr(t_stack_ab *this)
{
	ra(this);
	rb(this);
}
