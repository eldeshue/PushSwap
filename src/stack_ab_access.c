/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:01:20 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/13 20:03:09 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

int	a_top(t_stack_ab *this)
{
	return (this->pdata[this->pivot - 1]);
}

int	b_top(t_stack_ab *this)
{
	return (this->pdata[this->pivot]);
}

int	a_bot(t_stack_ab *this)
{
	return (this->pdata[this->a_bot]);
}

int	b_bot(t_stack_ab *this)
{
	return (this->pdata[this->b_bot]);
}
