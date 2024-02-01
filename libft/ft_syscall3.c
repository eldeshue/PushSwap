/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:40 by dogwak            #+#    #+#             */
/*   Updated: 2024/01/15 21:09:34 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	ft_pipe(int pipefd[2])
{
	int	rc;

	rc = pipe(pipefd);
	if (rc < 0)
	{
		perror(NULL);
		exit (1);
	}
	return (rc);
}

int	ft_dup2(int oldfd, int newfd)
{
	int	rc;

	rc = dup2(oldfd, newfd);
	if (rc < 0)
	{
		perror(NULL);
		exit (1);
	}
	return (rc);
}

pid_t	ft_wait(int *status)
{
	pid_t	pid;

	pid = wait(status);
	if (pid < 0)
	{
		perror(NULL);
		exit(1);
	}
	return (pid);
}

pid_t	ft_waitpid(pid_t pid, int *status, int options)
{
	pid_t	retpid;

	retpid = waitpid(pid, status, options);
	if (retpid < 0)
	{
		perror(NULL);
		exit(1);
	}
	return (retpid);
}
