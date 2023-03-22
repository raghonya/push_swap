#include <push_swap.h>

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

void	check_ascend(t_stack *a)
{
	int		flag;
	int		size;
	t_stack	*tmp;

	flag = 0;
	size = 0;
	tmp = a;
	while (a)
	{
		size++;
		a = a->next;
	}
	if (size == 2)
	a = a->next;
	while (a->next)
	{
		if (!(a->value > a->prev->value && a->value < a->next->value))
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		exit (0);
}

void	check_back(t_stack *a, int tiv)
{
	while (a->next)
	{
		err_push (a->value == tiv);
		a = a->next;
	}
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
		check_back(*a, new->value);
	}
	// check_ascend(*a);
	i = -1;
	while (nums[++i])
		free(nums[i]);
	free(nums);
	i = -1;
	// while (*a != NULL)
	// 	{printf ("%d\n", (*a)->value);
	// 	*a = (*a)->next;}
	
}
