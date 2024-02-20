/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:56:14 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/20 16:06:39 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_string/ft_string.h"
#include "../libft/libft.h"
#include "push_swap_bonus.h"
#include "stack_ab_bonus.h"

void	check_push_swap(t_stack_ab *pab)
{
	t_ft_string	buffer;

	buffer = construct_ftstr();
	if (buffer.pbuffer == NULL)
	{
		delete_ab(pab);
		write(2, "Error\n", 6);
		exit(1);
	}
	while (1)
	{
		buffer.getline(&buffer, 0);
		if (buffer.size == 0)
			break ;
		if (!select_query(pab, buffer.c_str(&buffer), buffer.size))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	destruct_ftstr(&buffer);
	if (is_ab_sorted(pab))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	delete_strs(char **strs)
{
	int	idx;

	idx = -1;
	while (strs[++idx] != NULL)
		free(strs[idx]);
	free(strs);
}

int	main(int argc, char *argv[])
{
	char		**tokens;
	t_stack_ab	*pab;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (*tokens == NULL)
			exit(0);
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
	check_push_swap(pab);
	delete_ab(pab);
}
