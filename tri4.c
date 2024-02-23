#include "push_swap.h"

void	remplissage_init(t_data *pile, int argc, int *stock)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		pile->tab[i] = stock[i];
		i++;
	}
}

int	l(char *argument)
{
	if ((*argument >= 48 && *argument <= 57) || *argument == '-')
		return (1);
	else
		return (0);
}

int	already_sort(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_a(argv[i]) > ft_a(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 3)
		return (1);
	if (already_sort(argc, argv))
		return (1);
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_a(argv[j]) == ft_a(argv[i]) || !l(argv[j]) || !l(argv[1])
				|| ft_a(argv[j]) < -2147483648 || ft_a(argv[j]) > 2147483647
				|| ft_a(argv[1]) < -2147483648 || ft_a(argv[1]) > 2147483647)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
