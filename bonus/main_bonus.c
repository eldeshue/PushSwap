/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:56:14 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/06 20:10:28 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_string/ft_string.h"
#include "stack_ab_bonus.h"

void	check_push_swap(/*two stack ptr*/)
{

	while (1)
	{
		// getline, read till eof
		if ()
			break ;
		// input sanity check

		// compare and get command from input

		// manipulate stack

	}
	// check stack a all ordered and b empty
	if ()
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

}

void	delete_strs(char **strs)
{
	int		idx;

	idx = -1;
	while (strs[++idx] != NULL)
		free(strs[idx]);
	free(strs);
}

int	main(int argc, char *argv[])
{
	char		**tokens;
	t_stack_ab	*pab;
	// two stack

	if (argc == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		// construct two stack
		delete_strs(tokens);
	}
	else
	{
		tokens = argv + 1;
		// construct two stack
	}
	if (pab == NULL)	// stack construct failed.
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	// check_push_swap(two stack);
}
