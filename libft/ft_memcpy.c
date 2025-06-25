/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:49:13 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	to = (char *)dest;
	from = (const char *)src;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}

//test
/*
#include <stdio.h>
int	main(void)
{
	char	test[6] = "Hello";
	char	test2[6];

	ft_memcpy(test2, test, 6);
	printf("%s", test2);
}
*/
