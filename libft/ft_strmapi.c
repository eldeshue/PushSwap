/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:00:23 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/10 18:50:50 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result_str;
	size_t			length;
	size_t			idx;

	length = ft_strlen(s);
	result_str = (char *)ft_malloc(sizeof(char) * (length + 1));
	idx = 0;
	while (idx < length)
	{
		result_str[idx] = f(idx, s[idx]);
		idx++;
	}
	result_str[idx] = '\0';
	return (result_str);
}
