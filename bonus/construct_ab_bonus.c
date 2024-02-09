/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ab_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:01:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/08 19:37:31 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_parser_bonus.h"
#include "stack_ab_bonus.h"
#include <stdlib.h>

// construct ab stack.
// parser module needed
// return NULL if insane.
t_stack_ab	*new_ab(char **strs)
{
	t_stack_ab	*this;
	int			idx;
	const int	str_cnt = ascii_number_sanity_check(strs);

	if (str_cnt == 0)
		return (NULL);
	this = (t_stack_ab *)malloc(sizeof(t_stack_ab));
	if (this == NULL)
		return (NULL);
	this->pdata = (int *)malloc(sizeof(int) * str_cnt);
	if (this->pdata == NULL)
		return (NULL);
	idx = str_cnt;
	while (--idx >= 0)
		this->pdata[idx] = ft_atoi(strs[str_cnt - 1 - idx]);
	if (!normailize_int(this->pdata, this->size))
		return (NULL);
	this->a_bot = 0;
	this->b_bot = str_cnt;
	this->pivot = str_cnt - 1;
	this->size = str_cnt;
	return (this);
}

void	delete_ab(t_stack_ab *this)
{
	free(this->pdata);
	free(this);
}
