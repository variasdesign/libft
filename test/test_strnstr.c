#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *result;
	char *src = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	char *dst = malloc(sizeof(char) * (strlen(argv[2]) + 1));
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	if (argc != 3)
	{
		printf("Please enter a haystack string followed by a needle string.\n");
		return (0);
	}
	printf("You've entered %s and %s as arguments.\n\n", argv[1], argv[2]);
	printf("Testing with size 0...\n");
	result = ft_strnstr(dst, src, 0);
	printf("Result:\nsubstring pos: %s\n\n", result);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 5...\n");
	result = ft_strnstr(dst, src, 5);
	printf("Result:\nsubstring pos: %s\n\n", result);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 10...\n");
	result = ft_strnstr(dst, src, 10);
	printf("Result:\nsubstring pos: %s\n\n", result);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 20...\n");
	result = ft_strnstr(dst, src, 20);
	printf("Result:\nsubstring pos: %s\n\n", result);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 50...\n");
	result = ft_strnstr(dst, src, 50);
	printf("Result:\nsubstring pos: %s\n\n", result);
	return (0);
}
