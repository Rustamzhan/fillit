/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:24:45 by astanton          #+#    #+#             */
/*   Updated: 2019/02/08 19:50:56 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_full_board(char **board, int init_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < init_size)
	{
		while (board[x][y] != '\0' && board[x][y] != '\n')
			write(1, &board[x][y++], 1);
		write(1, "\n", 1);
		y = 0;
		x++;
	}
}

static void	fill_with_letters(char **board, t_list *tetrominoes)
{
	t_list		*current;
	int			x;
	int			y;
	int			i;
	t_tetromino	*cont;

	current = tetrominoes;
	while (current)
	{
		cont = ((t_tetromino *)(current->content));
		i = 0;
		while (i < TETR_SIZE)
		{
			x = cont->start->x +
				cont->shape[i]->x;
			y = cont->start->y +
				cont->shape[i++]->y;
			board[x][y] = cont->letter;
		}
		current = current->next;
	}
	return ;
}

static void	free_board(char **board, int init_size)
{
	int	i;

	i = 0;
	while (i < init_size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

static void	fill_with_dots(char **board, int init_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < init_size)
		board[i++] = (char *)malloc(sizeof(char) * (init_size + 1));
	i = -1;
	while (++i < init_size)
	{
		j = 0;
		while (j <= init_size)
		{
			if (j == init_size && i < init_size - 1)
				board[i][j++] = '\n';
			else if (j == init_size && i == init_size - 1)
				board[i][j++] = '\0';
			else
				board[i][j++] = '.';
		}
	}
}

void		print_board(int init_size, t_list *tetrominoes)
{
	char	**board;

	board = (char **)malloc(sizeof(char *) * init_size);
	fill_with_dots(board, init_size);
	fill_with_letters(board, tetrominoes);
	print_full_board(board, init_size);
	free_board(board, init_size);
}
