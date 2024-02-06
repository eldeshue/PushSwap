/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/06 20:16:46 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_BONUS_H
# define STACK_AB_BONUS_H

# include "../ft_deque/ft_deque.h"

typedef struct s_stack_ab
{
	t_ft_deque	a;
	t_ft_deque	b;
}				t_stack_ab;

// construct ab stack.
// parser module needed
t_stack_ab		*new_ab(t_stack_ab *this, char **strs);
void			delete_ab(t_stack_ab *this);

// push

// swap

// rotate

// reverse rotate

// is sorted
int				is_ab_sorted(t_stack_ab *this);

#endif
