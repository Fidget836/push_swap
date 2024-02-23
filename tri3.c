#include "push_swap.h"

void	calculate_new(t_data *pile_a, int argc)
{
	int	tmp;

	tmp = (argc - 1) - pile_a->grand_tiers;
	pile_a->petit_tiers = pile_a->grand_tiers + (tmp * 1 / 3);
	pile_a->grand_tiers = pile_a->grand_tiers + (tmp * 2 / 3);
	if (pile_a->grand_tiers > argc - 4)
		pile_a->grand_tiers = argc - 4;
}

void	tri_3_last(t_data *pile_a)
{
	if (pile_a->tab[1] < pile_a->tab[0] && pile_a->tab[1]
		< pile_a->tab[2] && pile_a->tab[2] > pile_a->tab[0])
		sa(pile_a);
	else if (pile_a->tab[1] < pile_a->tab[0] && pile_a->tab[1]
		< pile_a->tab[2] && pile_a->tab[0] > pile_a->tab[2])
		ra(pile_a);
	else if (pile_a->tab[1] > pile_a->tab[0] && pile_a->tab[1]
		> pile_a->tab[2] && pile_a->tab[2] < pile_a->tab[0])
		rra(pile_a);
	else if (pile_a->tab[1] < pile_a->tab[0] && pile_a->tab[1]
		> pile_a->tab[2] && pile_a->tab[2] < pile_a->tab[0])
	{
		ra(pile_a);
		sa(pile_a);
	}
	else if (pile_a->tab[1] > pile_a->tab[0] && pile_a->tab[1]
		> pile_a->tab[2] && pile_a->tab[2] > pile_a->tab[0])
	{
		rra(pile_a);
		sa(pile_a);
	}
}

void	tri_a(t_data *pile_a, t_data *pile_b, int argc)
{
	while (pile_b->i < pile_a->grand_tiers && pile_a->i != 3)
	{
		if (pile_a->tab[0] > pile_a->grand_tiers)
		{
			ra(pile_a);
			pile_a->count_action++;
		}
		else if (pile_a->tab[0] <= pile_a->grand_tiers)
		{
			pb(pile_a, pile_b);
			pile_a->count_action++;
			if (pile_b->i > 1 && pile_b->tab[0]
				<= pile_a->petit_tiers && pile_a->i != 3)
			{
				rb(pile_b);
				pile_a->count_action++;
			}
		}
	}
	calculate_new(pile_a, argc);
}

void	tri_b(t_data *pile_a, t_data *pile_b)
{
	int	temp;

	while (pile_b->i != 0)
	{
		pile_a->k = 0;
		while (pile_b->tab[pile_a->k] != pile_b->i)
			pile_a->k++;
		temp = pile_b->i;
		while (temp != pile_b->tab[0])
		{
			if (pile_b->tab[0] == temp - 1)
				pa(pile_a, pile_b);
			else if (pile_a->k < (temp / 2))
				rb(pile_b);
			else
				rrb(pile_b);
		}
		if (pile_a->tab[0] == temp - 1)
		{
			pa(pile_a, pile_b);
			sa(pile_a);
		}
		else
			pa(pile_a, pile_b);
	}
}

void	tri_5(t_data *pile_a, t_data *pile_b)
{
	while (pile_a->i != 2)
	{
		if (pile_a->tab[0] <= 3)
			pb(pile_a, pile_b);
		else
			ra(pile_a);
	}
	if (pile_a->tab[0] == 5)
		sa(pile_a);
	while (pile_b-> i != 0)
	{
		if (pile_b->tab[0] == pile_b->i)
			pa(pile_a, pile_b);
		else if (pile_b->tab[1] == pile_b->i)
			rb(pile_b);
		else if (pile_b->tab[2] == pile_b->i)
			rrb(pile_b);
	}
}
