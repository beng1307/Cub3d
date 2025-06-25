/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:16:58 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
	}
	return (ch);
}

//test
/*
#include <stdio.h>
 
int	main(void)
{
	char	ch;

	ch = 'A';
	printf("%c in uppercase is represented as  %c", ch, toupper(ch));
}
*/
