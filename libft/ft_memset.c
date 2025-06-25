/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:24:22 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*set;

	i = 0;
	set = (char *)s;
	while (i < n)
	{
		*set = c;
		set++;
		i++;
	}
	return (s);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	test[16] = "ITestMyFunction";
	int		i;

	i = 0;
	printf("%s\n", test);
	ft_memset(test, 'x', 7);
	while (i < 16)
	{
		printf("%c", test[i]);
		i++;
	}
}
*/
