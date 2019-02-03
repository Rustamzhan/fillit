/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:28:43 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 22:34:31 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
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
	close(fd);
	return (0);
}
