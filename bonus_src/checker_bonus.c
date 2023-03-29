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
		ft_printf("KO");
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
	if (!a || b)
		ft_printf("KO");
	while (a->next)
	{
		if (a->value < a->next->value)
		{
			ft_printf ("KO");
			return (0);
		}
	}
	ft_printf ("OK");
	return (0);
}
