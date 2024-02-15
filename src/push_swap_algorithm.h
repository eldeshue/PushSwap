/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:57:11 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/14 16:27:34 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGORITHM_H
# define PUSH_SWAP_ALGORITHM_H

# include "../ft_vector/ft_vector.h"
# include "stack_ab.h"

// execute command and save the command
void	do_cmd(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int cmd);

// optimized insertion
// base case
void	sort_base_case(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size);

// quick + insertion
// recursively
// [), half open, end not included
void	quick_a(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int start, int end);

// sort
void	sort_ab(t_stack_ab *pab, t_ft_vector *p_cmd_vec);

#endif
