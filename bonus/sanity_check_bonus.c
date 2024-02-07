/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:22:04 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/07 19:25:14 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_parser_bonus.h"

static int	is_number(const char *str)
{
	int				idx;

	idx = -1;
	if (str[0] == '-' || str[0] == '+')
		idx = 0;
	while (str[++idx] != NULL)
		if (!ft_isdigit(str[idx]))
			return (0);
	return (1);
}

static int	get_number_start(const char *str)
{
	int				idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] == '0')
		idx++;
	return (idx);
}

static int	is_in_range(const char *str)
{
	const int	start_pos = get_number_start(str);
	const int	num_len = ft_strlen(str) - start_pos;

	if (num_len == 10)
	{
		if (str[0] == '-')
			return (ft_strncmp(str + start_pos, "2147483648", 10) < 0);
		else
			return (ft_strncmp(str + start_pos, "2147483647", 10) < 0);
	}
	else if (num_len < 10)
		return (1);
	else
		return (0);
}

int	ascii_number_sanity_check(const char **strs)
{
	int				idx;

	idx = -1;
	while (strs[++idx] != NULL)
		if (!is_number(strs[idx]))
			return (0);
	while (strs[++idx] != NULL)
		if (!is_in_range(strs[idx]))
			return (0);
	return (1);
}