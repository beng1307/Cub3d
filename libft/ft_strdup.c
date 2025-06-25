/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:22:19 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s) + 1;
	str = ft_calloc(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	return ((char *)(str));
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	test[20] = "Hello World";
	char	*test2;

	printf("%p\t%s\n", test, test);
	test2 = ft_strdup(test);
	printf("%p\t%s\n", test2, test2);
	free(test2);
}*/
