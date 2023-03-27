#include <push_swap.h>

int		sq_root(int n)
{
	int	i;

	i = 1;
	while (i < n / i)
	{
		if (n > i * i && n < (i + 1) * (i + 1))
			return (i);
		i++;
	}
	return (0);
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

void	sort_butterfly(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size;
	int		op;
	int		i;

	i = -1;
	tmp = *a;
	op = sq_root(size) + log_2(size);
	size = lstsize(*a);
	optimize_factor(&op, size);
	while (++i < size)
	{
		*a = tmp;
		//k
	}

}