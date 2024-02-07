/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:05:13 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/07 15:15:29 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_BONUS_H
# define STACK_AB_BONUS_H

// top of a equals (pivot - 1)
// top of b equals pivot
typedef struct s_stack_ab
{
	int	size;
	int	a_bot;
	int	b_bot;
	int	pivot;
	int	*pdata;
}				t_stack_ab;

// construct ab stack.
// parser module needed
t_stack_ab		*new_ab(char **strs);
void			delete_ab(t_stack_ab *this);

// push

// swap

// rotate

// reverse rotate

// is sorted
int				is_ab_sorted(t_stack_ab *this);

#endif
