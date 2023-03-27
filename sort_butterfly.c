#include <push_swap.h>

int		sq_root(int n)
{
	int	i;

	i = 0;
	while (++i < n / i)
		if (n > i * i && n < (i + 1) * (i + 1))
			return (i);
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

	i = 0;
	while (1)
		if (n >= pow_2(++i) && n < pow_2(i + 1))
			return (i);
}

void	optimize_factor(int *op, int size)
{
	*op = sq_root(size) + log_2(size);
}

void	sort_butterfly(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size;
	int		op;
	int		i;

	i = -1;
	tmp = *a;
	size = lstsize(*a);
	optimize_factor(&op, size);
	printf ("optimizer: %d\n", op);
	while (++i < size)
	{
		*a = tmp;
		//k
	}

}