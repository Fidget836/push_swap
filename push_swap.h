#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	i;
	int	j;
	int	k;
	int	grand_tiers;
	int	petit_tiers;
	int	count_action;
	int	*tab;
}	t_data;

long	ft_a(char *nptr);
int		ft_verif(int argc, char **argv);
void	sa(t_data *pile_a);
void	sb(t_data *pile_b);
void	pa(t_data *pile_a, t_data *pile_b);
void	pb(t_data *pile_a, t_data *pile_b);
void	ra(t_data *pile_a);
void	rb(t_data *pile_b);
void	rra(t_data *pile_a);
void	rrb(t_data *pile_b);
void	new_tab_plus1(t_data *pile, t_data *pile2);
void	new_tab_moins1(t_data *pile);
void	tri_a(t_data *pile_a, t_data *pile_b, int argc);
void	print(t_data *pile_a, t_data *pile_b);
void	tri_3_last(t_data *pile_a);
void	tri_b(t_data *pile_a, t_data *pile_b);
void	tri_5(t_data *pile_a, t_data *pile_b);
void	remplissage_init(t_data *pile, int argc, int *stock);

#endif
