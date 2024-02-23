#include "push_swap.h"

void	pb(t_data *pile_a, t_data *pile_b)
{
	new_tab_plus1(pile_b, pile_a);
	new_tab_moins1(pile_a);
	pile_b->i++;
	pile_a->i--;
	write(1, "pb\n", 3);
}

void	ra(t_data *pile_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_a->tab[0];
	while (i < pile_a->i - 1)
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_data *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_b->tab[0];
	while (i < pile_b->i - 1)
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i] = tmp;
	write(1, "rb\n", 3);
}

void	rra(t_data *pile_a)
{
	int	i;
	int	tmp;

	i = pile_a->i - 1;
	tmp = pile_a->tab[i];
	while (i >= 0)
	{
		pile_a->tab[i + 1] = pile_a->tab[i];
		i--;
	}
	pile_a->tab[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_data *pile_b)
{
	int	i;
	int	tmp;

	i = pile_b->i - 1;
	tmp = pile_b->tab[i];
	while (i >= 0)
	{
		pile_b->tab[i + 1] = pile_b->tab[i];
		i--;
	}
	pile_b->tab[0] = tmp;
	write(1, "rrb\n", 4);
}
