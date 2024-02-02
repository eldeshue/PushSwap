/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/01 19:11:48 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_BONUS_H
# define STACK_AB_BONUS_H

# include "../ft_deque/ft_deque.h"

typedef struct t_stack_ab
{
	t_ft_deque	a;
	t_ft_deque	b;
}				t_stack_ab;

t_stack_ab		construct_ab(void);
void			destruct_ab(t_stack_ab *this);

// stack a and b and command for two stack
// push

// swap

// rotate

// reverse rotate

#endif
