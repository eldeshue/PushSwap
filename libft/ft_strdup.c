/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:24:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/10 18:50:10 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			s1_len;
	char			*str;

	s1_len = ft_strlen(s1);
	str = (char *)ft_malloc(sizeof(char) * (s1_len + 1));
	ft_strlcpy(str, s1, (int)s1_len + 1);
	return (str);
}
