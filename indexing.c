#include <push_swap.h>

typedef	struct s_arr
{
	int	*a;
	int	size;
}	t_arr;

// void	voreve_sort(t_arr *arr)
// {
// 	int	i;

// 	i = 0;
// 	if (arr->size > 2)
// }

void	indexing(t_stack **a)
{
	t_stack	*tmp;
	t_arr	arr;
	int	i;

	i = -1;
	tmp = *a;
	arr.size = lstsize(*a);
	arr.a = malloc(sizeof(int) * arr.size);
	while (*a)
	{
		arr.a[++i] = (*a)->value;
		*a = (*a)->next;
	}
	*a = tmp;
}