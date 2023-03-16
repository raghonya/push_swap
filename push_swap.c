#include <push_swap.h>

void	err_push(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

void	print(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	*a = tmp;
	printf ("printi ardyunq\n");
	while ((*a) != NULL)
		{printf ("%d\n", (*a)->value);
		*a = (*a)->next;}
	*a = tmp;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc == 1)
		return (0);
	b = malloc(sizeof(t_stack));
	b->prev = NULL;
	check_args(&a, argc, argv);
	// swap_a(&a);
	// printf ("swap arajin\n");
	// print(&a);
	// swap_a(&a);
	// printf ("swap erkrord\n");
	// print(&a);
	// system("leaks push_swap");
	return (0);
}