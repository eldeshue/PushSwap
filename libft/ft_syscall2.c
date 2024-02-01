/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:03:27 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/23 18:48:02 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

ssize_t	ft_read(int fd, void *buf, size_t count)
{
	ssize_t	rc;

	rc = (ssize_t)read(fd, buf, count);
	if (rc < 0)
	{
		perror(NULL);
		exit(1);
	}
	return (rc);
}

ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	rc;

	rc = (ssize_t)write(fd, buf, count);
	if (rc < 0)
	{
		perror(NULL);
		exit(1);
	}
	return (rc);
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		exit(1);
	}
	return (pid);
}

void	ft_execve(const char *pathname, char *const argv[], char *const envp[])
{
	if (execve(pathname, argv, envp) < 0)
	{
		perror(NULL);
		exit(127);
	}
}
