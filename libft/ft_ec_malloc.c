#include "libft.h"

void *ft_ec_malloc(unsigned int size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_fatal("in function malloc() while allocating memory");
	return (ptr);
}
