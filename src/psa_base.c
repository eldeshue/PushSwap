/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psa_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:41:32 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/15 13:28:27 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"

/*
static void	sort_3(void)
{
}

static void	sort_4(void)
{
}

static void	sort_5(void)
{
}
*/

// optimized insertion sort
void	sort_base_case(t_stack_ab *pab, t_ft_vector *p_cmd_vec, int size)
{
	if (size == 2 && a_top(pab) > pab->pdata[pab->pivot - 2])
		do_cmd(pab, p_cmd_vec, SA);
	/*
	else if (size == 3)
		;
	else if (size == 4)
		;
	else if (size == 5)
		;
		*/
}
