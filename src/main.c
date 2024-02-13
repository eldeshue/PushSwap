/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:42:12 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/13 15:59:11 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algorithm.h"
#include "push_swap_command.h"
#include "push_swap_parser.h"
#include "stack_ab.h"

void	delete_strs(char **strs)
{
	int	idx;

	idx = -1;
	while (strs[++idx] != NULL)
		free(strs[idx]);
	free(strs);
}

void	solve_push_swap(t_stack_ab *pab)
{
	// construct command buffer vector
	// sort ab, command buffer filled.
	// print result, (optimization, decoding)
	// destruct command buffer
}

int	main(int argc, char *argv[])
{
	char		**tokens;
	t_stack_ab	*pab;

	if (argc == 1) // no argument, do nothing
		exit(1);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		pab = new_ab(tokens);
		delete_strs(tokens);
	}
	else
	{
		tokens = argv + 1;
		pab = new_ab(tokens);
	}
	if (pab == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	solve_push_swap(pab);
	delete_ab(pab);
}
