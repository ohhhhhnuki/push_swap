#include "../includes/push_swap.h"

static void	memory_allocate(t_info *info, size_t size)
{
	info->stack.a = ft_calloc(size, sizeof(int));
	if (info->stack.a == NULL)
		error_message(info);
	info->stack.compression_a = ft_calloc(size, sizeof(int));
	if (info->stack.compression_a == NULL)
		error_message(info);
	info->stack.b = ft_calloc(size, sizeof(int));
	if (info->stack.b == NULL)
		error_message(info);
	info->stack.compression_b = ft_calloc(size, sizeof(int));
	if (info->stack.compression_b == NULL)
		error_message(info);
}

static void	string_to_array(t_info *info)
{
	char	**str;
	int 	i;
	int		j;

	memory_allocate(info, ft_strlen(info->argv[1]));
	info->argc = str_separate_count(info->argv[1], ' ');
	info->stack.head_a = info->argc - 1;
	str = ft_split(info->argv[1], ' ');
	i = 0;
	j = info->argc - 1;
	while (i < info->argc)
	{
		info->stack.a[i] = ps_atoi(str[j], info);
		i++;
		j--;
	}
}

static void	argv_to_array(t_info *info)
{
	memory_allocate(info, info->argc);
	int i = 0;
	int	j = info->argc;
	while (i < info->argc)
	{
		info->stack.a[i] = ps_atoi(info->argv[j], info);
		i++;
		j--;
	}
}

void	stack_argv(t_info *info)
{
	if (ft_strchr(info->argv[1], ' ') != NULL)
		string_to_array(info);
	else
		argv_to_array(info);
	compression_array(info);
}