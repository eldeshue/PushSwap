/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ab_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:01:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/06 20:14:29 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack_ab_bonus.h"
#include "push_swap_parser_bonus.h"

// construct ab stack.
// parser module needed
t_stack_ab	*new_ab(t_stack_ab *this, char **strs)
{
	// input strs sanity check.
	// return NULL if insane.

	// construct two ft_deque, a and b.
	// construction failed, return NULL

	// set ab with strs.
}

void	delete_ab(t_stack_ab *this)
{
	destruct_ftdeque(&this->a);
	destruct_ftdeque(&this->b);
	free(this);
}
