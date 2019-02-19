/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:28:48 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:21:30 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**create_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	if (!(board = malloc((size + 1) * sizeof(char*))))
		return (NULL);
	while (i < size)
	{
		board[i] = ft_strnew(size);
		ft_bzero(board[i], size);
		i++;
	}
	board[i] = NULL;
	return (board);
}

static void	fill_board(int x, int y, t_point **shape, char **board)
{
	t_point	*new;
	int		i;

	i = 0;
	while (i < TETR_SIZE)
	{
		new = sum_points(x, y, shape[i]);
		board[new->x][new->y] = !board[new->x][new->y];
		free(new);
		i++;
	}
}

static int	fill_if_fit(int x, int y, t_tetromino *content, char **board)
{
	t_point	*new;
	t_point	**shape;
	t_point	*start;
	int		i;

	shape = content->shape;
	start = content->start;
	i = 0;
	while (i < TETR_SIZE)
	{
		new = sum_points(x, y, shape[i]);
		if (board[new->x][new->y])
		{
			free(new);
			return (0);
		}
		else
			free(new);
		i++;
	}
	fill_board(x, y, shape, board);
	change_point(start, x, y);
	return (1);
}

static int	solve_board(char **board, t_list *tetrominoes, int size)
{
	t_list		*current;
	t_tetromino	*cont;
	int			x;
	int			y;

	current = tetrominoes;
	if (!current)
		return (1);
	cont = (t_tetromino*)current->content;
	x = -1;
	while (++x < (size - cont->width))
	{
		y = -1;
		while (++y < (size - cont->height))
		{
			if (fill_if_fit(x, y, cont, board))
			{
				if (!solve_board(board, current->next, size))
					fill_board(x, y, cont->shape, board);
				else
					return (1);
			}
		}
	}
	return (0);
}

int			solve(t_list *tetrominoes)
{
	char	**board;
	int		init_size;

	init_size = ft_sqrt_up(TETR_SIZE * ft_lst_len(tetrominoes));
	board = create_board(init_size);
	while (!solve_board(board, tetrominoes, init_size))
	{
		ft_clear_2d_arr((void**)board);
		init_size++;
		board = create_board(init_size);
	}
	ft_clear_2d_arr((void**)board);
	return (init_size);
}
