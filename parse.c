#include <push_swap.h>

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\r' \
		|| c == '\v' || c == '\f' || c == ' ');
}

long	ft_atol(char *str)
{
	int		sign;
	long	num;
	
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
	if (num > INT_MAX || num < INT_MIN)
		exit (1);
	return (sign * num);
}

void	nodeadd_back(t_stack **head, t_stack *new)
{
	t_stack	*a;

	err_push(!head);
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
		return ;
	}
	a = *head;
	while ((*head)->next)
		*head = (*head)->next;
	new->prev = *head;
	(*head)->next = new;
	*head = a;
}

char	**create_nums(int argc, char **argv)
{
	char	**nums;
	char	*join;
	int		i;

	i = 1;
	join = "";
	while (i < argc)
		join = ft_strjoin (join, argv[i++]);
	i = -1;
	while (join[++i])
		err_push(join[i] != '+' && join[i] != '-' \
		&& join[i] != ' ' && !ft_isdigit(join[i]));
	nums = ft_split (join, ' ');
	err_push(!nums || !(*nums));
	free(join);
	return (nums);
}

void	check_args(t_stack **a, int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*new;
	char	**nums;
	int		i;

	nums = create_nums(argc, argv);
	i = -1;
	while (nums[++i])
	{
		new = malloc(sizeof(t_stack));
		err_push(!new);
		new->value = ft_atol(nums[i]);
		new->next = NULL;
		nodeadd_back(a, new);
	}
	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
	i = -1;
	while (*a != NULL)
		{printf ("%d\n", (*a)->value);
		*a = (*a)->next;}
}
