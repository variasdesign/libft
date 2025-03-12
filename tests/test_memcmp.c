#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int result = 0;
	char *src = malloc(sizeof(char) * (strlen(argv[2]) + 1));
	char *dst = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	strcpy(src, argv[2]);
	strcpy(dst, argv[1]);
	if (argc != 3)
	{
		printf("Please enter a source string followed by a destination string.\n");
		return (0);
	}
	printf("You've entered %s and %s as arguments.\n\n", argv[1], argv[2]);
	printf("Testing with size 0...\n");
	result = ft_memcmp(dst, src, 0);
	printf("Result: %d\n\n", result);
	printf("Testing with size 5...\n");
	result = ft_memcmp(dst, src, 5);
	printf("Result: %d\n\n", result);
	printf("Testing with size 10...\n");
	result = ft_memcmp(dst, src, 10);
	printf("Result: %d\n\n", result);
	printf("Testing with size 20...\n");
	result = ft_memcmp(dst, src, 20);
	printf("Result: %d\n\n", result);
	printf("Testing with size 50...\n");
	result = ft_memcmp(dst, src, 50);
	printf("Result: %d\n\n", result);
	return (0);
}
