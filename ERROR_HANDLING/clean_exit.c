#include "../cub3d.h"

void	clean_exit(t_data *data, char *error_message)
{
	(void)data;
	while (*error_message)
		write(2, error_message++, 1);
	write(2, "\n", 1);

	exit(1);
}