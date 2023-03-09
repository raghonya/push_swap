#include <push_swap.h>

static void	universal_func(int a)
{
	if (a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\r' \
		|| c == '\v' || c == '\f' || c == ' ');
}

long	ft_atol(char *str)
{
	int	sign;
	int	num;
	
	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (ft_strlen (str) > 10)
		exit (1);
	while (ft_isdigit(*str))
		num = num * 10 + (*(str++) - 48);
	return (sign * num);
}

void	check_args(t_stack **a, int argc, char **argv)
{
	t_stack	*tmp;
	char	**nums;
	char	*join;
	int		i;

	i = 1;
	join = "";
	while (i < argc)
		join = ft_strjoin (join, argv[i++]);
	// printf ("%s\n", join);
	nums = ft_split (join, ' ');
	universal_func(!nums || !(*nums));
	// while (nums[++i])
	// 	ft_printf ("%s\n", nums[i]);
	i = -1;
	tmp = *a;
	// printf ("atol 0 == %li\n", ft_atol(nums[0]));
	while (nums[++i])
	{
		(*a)->index = i;
		(*a)->value = ft_atol(nums[i]);
		printf ("%d\n", (*a)->value);
		(*a)->next = ft_lstnew();
	}
	*a = tmp;
	free(join);
}