#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *src = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	char *dst = malloc(sizeof(char) * (strlen(argv[2]) + 1));
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	if (argc != 3)
	{
		printf("Please enter a source string followed by a destination string.\n");
		return (0);
	}
	printf("You've entered %s and %s as arguments.\n\n", argv[1], argv[2]);
	printf("Testing with size 0...\n");
	ft_strlcat(dst, src, 0);
	printf("Result:\ndst: %s\n\n", dst);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 5...\n");
	ft_strlcat(dst, src, 5);
	printf("Result:\ndst: %s\n\n", dst);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 10...\n");
	ft_strlcat(dst, src, 10);
	printf("Result:\ndst: %s\n\n", dst);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 20...\n");
	ft_strlcat(dst, src, 20);
	printf("Result:\ndst: %s\n\n", dst);
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);
	printf("Testing with size 50...\n");
	ft_strlcat(dst, src, 50);
	printf("Result:\ndst: %s\n\n", dst);
	return (0);
}
