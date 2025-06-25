/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:49:51 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Prints Characters.
size_t	ft_print_c(int c)
{
	size_t	count;

	count = 0;
	return (count += write(1, &c, 1));
}

// Prints strings.
size_t	ft_print_s(char *str)
{
	size_t	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (str[count] != '\0')
		count += write(1, &str[count], 1);
	return (count);
}
