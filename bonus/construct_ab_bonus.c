/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_ab_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:01:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/07 15:59:24 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack_ab_bonus.h"
#include "push_swap_parser_bonus.h"

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
	return (this);
}

void	delete_ab(t_stack_ab *this)
{
	free(this->pdata);
	free(this);
}
