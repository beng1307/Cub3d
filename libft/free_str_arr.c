
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
