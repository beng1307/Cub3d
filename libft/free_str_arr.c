/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:49:39 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/26 12:49:41 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_arr(char ***arr)
{
	int	index;

	if (!arr || !*arr)
		return ;
	index = 0;
	while ((*arr)[index])
	{
		free((*arr)[index]);
		(*arr)[index++] = NULL;
	}
	free(*arr);
	*arr = NULL;
}
