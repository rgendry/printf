#include "float.h"

void	ft_bzero(void *str, size_t len)
{
	char	*str1;
	size_t	i;

	i = 0;
	str1 = str;
	while (i < len)
	{
		str1[i] = 0;
		i++;
	}
}
