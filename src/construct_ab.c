/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:01:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/12 20:55:54 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_parser.h"
#include "stack_ab.h"
#include <stdlib.h>

// construct ab stack.
// parser module needed
// return NULL if insane.
t_stack_ab	*new_ab(char **strs)
{
	t_stack_ab	*this;
	int			idx;
	const int	str_cnt = ascii_number_sanity_check((const char **)strs);

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
	this->a_bot = 0;
	this->b_bot = str_cnt;
	this->pivot = str_cnt - 1;
	this->size = str_cnt;
	if (!normailize_int(this->pdata, this->size))
		return (NULL);
	return (this);
}

void	delete_ab(t_stack_ab *this)
{
	free(this->pdata);
	free(this);
}
