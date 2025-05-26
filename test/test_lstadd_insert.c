#include "libft.h"

int main(void)
{
	t_list *first;
	t_list *second;
	t_list *third;

	first = ft_lstnew((void *)"hello");
	second = ft_lstnew((void *)"sup");
	third = ft_lstnew((void *)"me first");
	ft_lstadd_back(&first, second);
	ft_lstadd_insert(&first, third, 0);
}
