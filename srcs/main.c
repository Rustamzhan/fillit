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

static void	free_list(t_list *lst)
{
	t_list	*head;
	t_list	*current;
	int		i;

	current = lst;
	while (current)
	{
		head = current->next;
		i = 0;
		while (i < TETR_SIZE)
			free(((t_tetromino *)(current->content))->shape[i++]);
		free(((t_tetromino *)(current->content))->shape);
		free(((t_tetromino *)(current->content))->start);
		free(current->content);
		free(current);
		current = head;
	}
}

int			main(int ac, char **av)
{
	int				fd;
	static t_list	*lst;
	int				init_size;

	if (ac != 2)
	{
		ft_putstr("usage: a.out source_file\n");
		exit(1);
	}
	lst = NULL;
	fd = open(av[1], O_RDONLY);
	validating_file(fd, &lst);
	init_size = solve(lst);
	print_board(init_size, lst);
	free_list(lst);
	close(fd);
	return (0);
}
