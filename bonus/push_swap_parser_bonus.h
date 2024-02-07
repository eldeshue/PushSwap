/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogwak <dogwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:59:28 by dogwak            #+#    #+#             */
/*   Updated: 2024/02/07 15:59:51 by dogwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PARSER_BONUS_H
# define PUSH_SWAP_PARSER_BONUS_H

# include "../libft/libft.h"

// argument sanitiy check
// range check and digit check needed.
// using string compare, range check
// return number of string in the strs, 0 if failed.
int		ascii_number_sanity_check(const char **strs);

// normalize
// convert all values to consecutive integer starts from 0
int		normailize_int(int *arr, int size);

#endif
