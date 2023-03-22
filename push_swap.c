#include <push_swap.h>

void	err_push(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		exit(1);
	}
}

void	print(t_stack *a)
{
	// printf ("printi ardyunq\n");
	while (a != NULL)
	{
		printf ("%d\n", a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc == 1)
		return (0);
	check_args(&a, argc, argv);
	printf ("do rotate\n\n");
	print (a);
	rotate(&a);
	printf ("\nposle rotate\n\n");
	print (a);
	// rrotate(&a);
	// printf ("\nposle rotate\n\n");
	// print (&a);
	// rrotate(&a);
	// printf ("\nposle rotate\n\n");
	// print (&a);
	return (0);
}