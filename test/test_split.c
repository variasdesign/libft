#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	size_t i;
	char **split_str;

	if (argc != 3)
		printf("Please introduce a single string, followed by a single char which will act as delimiter");
	split_str = ft_split(argv[1], argv[2][0]);	
	printf("Printing split words...\n");
	i = 0;
	while (split_str[i])
	{
		printf("%s\n", split_str[i]);
		i++;
	}
	printf("Done!\n");
	return (0);
}
