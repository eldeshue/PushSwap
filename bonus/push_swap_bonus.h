/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:02:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/09 16:55:38 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "stack_ab_bonus.h"

// query selector
// take string as an input and manipulate ab
// return 0 if failed.
int select_query(t_stack_ab *this, const char *query, const int query_size);

#endif
