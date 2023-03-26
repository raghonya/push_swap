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
	if (a)
	while (a != NULL)
	{
		printf ("value: %d, index: %d\n", a->value, a->index);
		//printf ("%p\n", a);
		a = a->next;
	}
	else
		printf ("Datark a!!!\n");
}

int		sq_root(int n)
{
	int	i;

	i = 1;
	while (i < n / i)
	{
		if (n >= i * i && n < (i + 1) * (i + 1))
			return (i);
		i++;
	}
}

int		pow_2(int n)
{
	int i;

	i = 1;
	while (n--)
		i *= 2;
	return (i);
}

int		log_2(int n)
{
	int	i;

	while (1)
		if (n >= pow_2(++i) && n < pow_2(i + 1))
			return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	check_args(&a, argc, argv);
	size = lstsize(a);
	indexing(&a);
	//printf ("\nstack a\n\n");
	//print (a);
	//if (size == 2)
	//	swap_a(&a);
	//else if (size > 2 && size < 13)
	//	sort_under_12(&a, &b, size);
	//else
	//	sort_butterfly(&a, &b);
	//printf ("do gorcox\n\n");
	//print (a);
	//rotate(&a);
	//printf ("\nstack b\n\n");
	//print (b);
	////printf ("\ndo swap\n\n");
	//printf ("sortavorac a\n\n");
	//print (a);
	//swap_a(&a);
	//printf ("\nposle swap\n\n");
	//print (a);
	//printf ("\ndo pusha depi b\n\n");
	//print (a);
	//push_b(&a, &b);
	//printf ("\nposle pusha depi b\n\n");
	//print (a);
	return (0);
}