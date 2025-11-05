/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:06:19 by nel-yama          #+#    #+#             */
/*   Updated: 2025/11/05 19:06:19 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_print_sol(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		fprintf(stdout, "%d ", board[i]);
		i++;
	}
	fprintf(stdout, "%d\n", board[i]);
}

int	ft_is_safe(int *board, int row, int col)
{
	int	i;

	if (col == 0)
		return (1);
	i = 0;
	while (i < col)
	{
		if ((board[i] == row)
			|| (ft_abs(row - board[i]) == ft_abs(col - i)))
			return (0);
		i++;
	}
	return (1);
}

void	ft_solve_board(int *board, int n, int col)
{
	int	i;

	if (col == n)
	{
		ft_print_sol(board, n);
		return ;
	}
	i = 0;
	while (i < n)
	{
		if (ft_is_safe(board, i, col))
		{
			board[col] = i;
			ft_solve_board(board, n, col + 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*board;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n < 1)
		return (1);
	board = calloc(n, sizeof(int));
	if (!board)
		return (1);
	ft_solve_board(board, n, 0);
	free(board);
	return (0);
}
