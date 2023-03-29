#include <push_swap_bonus.h>

void	print(t_stack *a)
{
	if (a)
		while (a)
		{
			printf ("value: %d, index: %d\n", a->value, a->index);
			a = a->next;
		}
	else
		printf ("Datark a!!!\n");
}

void	is_ko(int a)
{
	if (a)
	{
		ft_printf("KO\n");
		exit (1);
	}
}

int main(int argc, char **argv)
{
	char	*(instr[12]);
	char	*input;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	fill(instr);
	check_args(&a, argc, argv);
	input = get_next_line(0);
	while (input)
	{
		check_input(input, instr);
		checking(&a, &b, input);
		input = get_next_line(0);
	}
	is_ko(!a || b);
	print(a);
	while (a->next)
	{
		is_ko(a->value > a->next->value);
		a = a->next;
	}
	ft_printf ("OK\n");
	return (0);
}
