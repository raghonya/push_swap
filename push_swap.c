#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	check_args(&a, argc, argv);
	// system("leaks push_swap");
	return (0);
}