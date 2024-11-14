#include "../libft.h"
#include <stdio.h>
#include <string.h>

void print_words(char **split_str)
{
	size_t i;

	printf("Printing split words...\n");
	i = 0;
	while (split_str[i])
	{
		printf("%s\n", split_str[i]);
		i++;
	}
	printf("Done!\n");
}

int main(int argc, char **argv)
{
	char **split_str;

	if (argc != 2)
		printf("Please introduce a single string");
	printf("Splitting string with delimiter SPACE...\n");
	split_str = ft_split(argv[1], ' ');	
	print_words(split_str);
	printf("Splitting string with delimiter \"...\n");
	split_str = ft_split(argv[1], '"');	
	print_words(split_str);
	printf("Splitting string with delimiter \\n...\n");
	split_str = ft_split(argv[1], '\n');	
	print_words(split_str);
	printf("Splitting string with delimiter a...\n");
	split_str = ft_split(argv[1], ' ');	
	print_words(split_str);
	return (0);
}
