#include "push_swap.h"

void	init_data(t_data *pile, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		pile->tab[i] = -1;
		i++;
	}
	pile->i = 0;
	pile->count_action = 0;
	pile->grand_tiers = (argc - 1) * 2 / 3;
	pile->petit_tiers = (argc - 1) / 3;
}

void	init_numbers(t_data *pile, int argc)
{
	int	i;
	int	j;
	int	count;
	int	*stock;

	stock = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		count = 1;
		j = 0;
		while (j < argc - 1)
		{
			if (pile->tab[i] > pile->tab[j])
				count++;
			j++;
		}
		stock[i] = count;
		i++;
	}
	remplissage_init(pile, argc, stock);
	free(stock);
}

void	free_tab(t_data *pile_a, t_data *pile_b)
{
	free (pile_a->tab);
	free (pile_b->tab);
}

int	malloc_init_tab(t_data *pile_a, t_data *pile_b, int argc)
{
	pile_a->tab = malloc(sizeof(int) * (argc - 1));
	if (!pile_a->tab)
		return (1);
	pile_b->tab = malloc(sizeof(int) * (argc - 1));
	if (!pile_b->tab)
		return (1);
	init_data(pile_a, argc);
	init_data(pile_b, argc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	pile_a;
	t_data	pile_b;

	if (ft_verif(argc, argv))
		return (0);
	if (malloc_init_tab(&pile_a, &pile_b, argc))
		return (0);
	while (pile_a.i < argc - 1)
	{
		pile_a.tab[pile_a.i] = ft_a(argv[pile_a.i + 1]);
		pile_a.i++;
	}
	init_numbers(&pile_a, argc);
	if (argc == 6)
	{
		tri_5(&pile_a, &pile_b);
		return (0);
	}
	while (pile_a.i != 3)
		tri_a(&pile_a, &pile_b, argc);
	tri_3_last(&pile_a);
	tri_b(&pile_a, &pile_b);
	free_tab(&pile_a, &pile_b);
	return (0);
}
