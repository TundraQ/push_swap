#include "libft.h"

void ft_fatal(char *message)
{
	char	error_message[100];

	ft_strlcpy(error_message, "Critical error ", 16);
	ft_strlcat(error_message, message, 99);
	ft_printf(error_message);
	exit(-1);
}
