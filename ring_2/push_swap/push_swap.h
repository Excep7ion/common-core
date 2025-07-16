/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meguetta <meguetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:28:17 by meguetta          #+#    #+#             */
/*   Updated: 2025/04/02 08:02:26 by meguetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/****************************** MACRO *****************************************/
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
/****************************** INCLUDE ***************************************/
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
/****************************** STRUCTURE *************************************/
typedef struct s_bag
{
	int				index;
	int				value;
	int				size;
	int				count;
	int				count_pa;
	int				count_pb;
	int				count_ra;
	int				count_rra;
	int				count_rb;
	int				count_rrb;
	int				count_rr;
	int				count_rrr;
	int				position;
	int				position_max;
	int				position_min;
	int				median;
	int				min_operations;
	int				target_position;
	int				target;
	int				tmp;
	int				max;
	int				min;
	int				winner;
	t_list			*copie_a;
	t_list			*copie_b;
}					t_bag;
/****************************** DISPLAY ***************************************/
void	display_stack(t_list **stack, int b);
/****************************** COMMANDS **************************************/
void	swap_a(t_list **stack_a, int b);
void	swap_b(t_list **stack_b, int b);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a, int b);
void	rotate_b(t_list **stack_b, int b);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a, int b);
void	reverse_rotate_b(t_list **stack_b, int b);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
/****************************** SORT ******************************************/
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b, t_bag *bag);
void	sort_five(t_list **stack_a, t_list **stack_b, t_bag *bag);
void	sort_one_hundred(t_list **stack_a, t_list **stack_b, t_bag *bag);
void	min_first(t_list **stack, int b, t_bag *bag);
void	max_first(t_list **stack, int b, t_bag *bag);
/****************************** SEARCH ****************************************/
int		search_min(t_list *stack, t_bag *bag);
int		search_max(t_list *stack, t_bag *bag);
int		search_median(t_list *stack, t_bag *bag);
int		search_position_min(t_list *stack, t_bag *bag);
int		search_position_max(t_list *stack, t_bag *bag);
int		search_winner(t_list *stack_a, t_list *stack_b, t_bag *bag);
/****************************** CHECK *****************************************/
void	check_size(t_list **stack_a, t_list **stack_b, t_bag *bag);
int		check_duplicate(t_list *stack_a);
int		check_overflow(char **argv, int b);
void	check_arguments(t_list **stack_a, int argc, char **argv);
int		check_if_digit(char **argv);
int		check_if_digit_2(char **argv);
int		check_if_sort(t_list *stack_a);
int		parsing(int argc, char **argv);
/****************************** ALGO ******************************************/
void	algo(t_list **stack_a, t_list **stack_b, t_bag *bag);
void	count_operations(t_list *stack_a, t_list *stack_b, t_bag *bag);
int		count_rra(t_list *stack_a, t_list *stack_b, t_bag *bag);
void	ra_rra_rb_rrb(t_list *stack_a, t_list *stack_b, t_bag *bag, int p);
int		target_position(int content, t_list *stack_b, t_bag *bag);
int		max_position(t_list *stack_b, t_bag *bag);
int		lower_position_close(t_list *stack_b, int content, t_bag *bag);
int		rr(int ra, int rb, t_bag *bag);
int		rrr(int rra, int rrb, t_bag *bag);
void	execute_operations(t_list **stack_a, t_list **stack_b, t_bag *bag);
void	execute_operations_next(t_list **stack_a, t_list **stack_b, t_bag *bag);
int		rb_or_rrb(t_list *stack_b, t_bag *bag);
int		position_winner(t_list *stack_a, t_list *stack_b, t_bag *bag);
void	init_bag(t_bag **bag, t_list *stack_a);
void	init_count(t_bag **bag);
void	check_rr_and_rrr(t_bag **bag);
void	addition_count(t_bag **bag);
void	actions(t_list **stack_a, t_list **stack_b, t_bag *bag);
/****************************** FREE ******************************************/
void	free_stack(t_list *stack_a);
#endif
