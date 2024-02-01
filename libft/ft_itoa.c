/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:20:48 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/10 18:46:13 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_length_from_int(long long n)
{
	size_t				length;

	if (n == 0)
		return (2);
	length = 1;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char				*str;
	size_t				str_size;

	str_size = get_str_length_from_int((long long)n);
	str = (char *)ft_malloc(str_size * sizeof(char));
	ft_conv_itoa(str, n);
	return (str);
}
