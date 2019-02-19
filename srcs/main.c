/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:28:43 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:19:58 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_list(t_list *tetrominoes)
{
	t_list		*head;
	t_list		*current;
	int			i;
	t_tetromino	*cont;

	current = tetrominoes;
	while (current)
	{
		cont = ((t_tetromino *)(current->content));
		head = current->next;
		i = 0;
		while (i < TETR_SIZE)
			free(cont->shape[i++]);
		free(cont->shape);
		free(cont->start);
		free(current->content);
		free(current);
		current = head;
	}
}

int			main(int ac, char **av)
{
	int				fd;
	static t_list	*tetrominoes;
	int				init_size;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		exit(1);
	}
	tetrominoes = NULL;
	fd = open(av[1], O_RDONLY);
	validating_file(fd, &tetrominoes);
	init_size = solve(tetrominoes);
	print_board(init_size, tetrominoes);
	free_list(tetrominoes);
	close(fd);
	return (0);
}
