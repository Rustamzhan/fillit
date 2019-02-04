/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:24:45 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:20:28 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_last(char **board, int init_size)
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

static void	print_fill_board(char **board, t_list *lst, int init_size)
{
	t_list	*take;
	int		x;
	int		y;
	int		i;

	take = lst;
	while (take)
	{
		i = 0;
		while (i < TETR_SIZE)
		{
			x = ((t_tetromino *)(take->content))->start->x +
				((t_tetromino *)(take->content))->shape[i]->x;
			y = ((t_tetromino *)(take->content))->start->y +
				((t_tetromino *)(take->content))->shape[i++]->y;
			board[x][y] = ((t_tetromino *)(take->content))->letter;
		}
		take = take->next;
	}
	print_last(board, init_size);
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

void		print_board(int init_size, t_list *lst)
{
	char	**board;
	int		i;
	int		j;

	board = (char **)malloc(sizeof(char *) * (init_size));
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
	print_fill_board(board, lst, init_size);
	free_board(board, init_size);
}
