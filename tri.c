#include "push_swap.h"

void	sa(t_data *pile_a)
{
	int	tmp;

	tmp = pile_a->tab[0];
	pile_a->tab[0] = pile_a->tab[1];
	pile_a->tab[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_data *pile_b)
{
	int	tmp;

	tmp = pile_b->tab[0];
	pile_b->tab[0] = pile_b->tab[1];
	pile_b->tab[1] = tmp;
	write(1, "sb\n", 3);
}

void	new_tab_moins1(t_data *pile)
{
	int	i;

	i = 0;
	while (i < pile->i)
	{
		pile->tab[i] = pile->tab[i + 1];
		i++;
	}
}

void	new_tab_plus1(t_data *pile, t_data *pile2)
{
	int	i;

	i = pile->i + 1;
	while (i > 0)
	{
		pile->tab[i] = pile->tab[i - 1];
		i--;
	}
	pile->tab[0] = pile2->tab[0];
}

void	pa(t_data *pile_a, t_data *pile_b)
{
	new_tab_plus1(pile_a, pile_b);
	new_tab_moins1(pile_b);
	pile_a->i++;
	pile_b->i--;
	write(1, "pa\n", 3);
}
