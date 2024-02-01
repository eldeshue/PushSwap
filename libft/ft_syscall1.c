/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:40:52 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/23 17:29:59 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
	{
		perror(NULL);
		exit(128);
	}
	return (rc);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
	{
		perror(NULL);
		exit(1);
	}
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror(NULL);
		exit(1);
	}
	return (ptr);
}

void	ft_free(void *ptr)
{
	free(ptr);
}
