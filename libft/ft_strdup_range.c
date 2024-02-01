/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:16:43 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/10 18:49:58 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_range(const char *origin, size_t start, size_t end)
{
	char			*dst;
	size_t			idx;

	if (start > end)
		return (NULL);
	dst = (char *)ft_malloc(sizeof(char) * (end - start + 1));
	idx = 0;
	while (idx + start < end)
	{
		dst[idx] = origin[start + idx];
		idx++;
	}
	dst[idx] = '\0';
	return (dst);
}
