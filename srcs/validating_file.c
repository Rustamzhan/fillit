/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:07:29 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:22:21 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_for_connections(char *buf, int i)
{
	int nbr;

	nbr = 0;
	nbr += ((buf[i + 1] == FULL) ? 1 : 0);
	if (i < LINE_LEN * 3)
		nbr += ((buf[i + LINE_LEN] == FULL) ? 1 : 0);
	if (i > 0)
		nbr += ((buf[i - 1] == FULL) ? 1 : 0);
	if (i > TETR_SIZE)
		nbr += ((buf[i - LINE_LEN] == FULL) ? 1 : 0);
	return (nbr);
}

static int	check_buf(char *buf)
{
	int i;
	int cols;
	int n_empt;
	int n_full;
	int	n_connct;

	i = -1;
	cols = 0;
	n_empt = 0;
	n_full = 0;
	n_connct = 0;
	while (buf[++i] != '\0')
	{
		if ((buf[i] != FULL && buf[i] != EMP && buf[i] != '\n'
				&& buf[i] != '\0') || cols++ > LINE_LEN)
			return (1);
		cols = ((buf[i] == '\n') ? 0 : cols);
		if (buf[i] == FULL)
		{
			n_full++;
			n_connct += check_for_connections(buf, i);
		}
		n_empt += ((buf[i] == EMP) ? 1 : 0);
	}
	return ((n_full != 4 || n_empt != 12 || n_connct < 5) ? 1 : 0);
}

static void	abort_prog(char *buf)
{
	free(buf);
	ft_putstr("error\n");
	exit(1);
}

static void	create_list(t_list **tetrominoes, int letter, char *buf)
{
	t_list	*current;
	t_list	*new;

	current = *tetrominoes;
	if (!*tetrominoes)
	{
		*tetrominoes = ft_lstnew(NULL, 0);
		current = *tetrominoes;
		current->content = create_content(letter, buf);
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new = ft_lstnew(NULL, 0);
		current->next = new;
		current = current->next;
		current->content = create_content(letter, buf);
	}
	return ;
}

void		validating_file(int fd, t_list **tetrominoes)
{
	char			*buf;
	int				ret;
	int				letter;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || read(fd, buf, 0) < 0)
		abort_prog(buf);
	letter = 'A' - 1;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (check_buf(buf))
			abort_prog(buf);
		if (buf[ret - 1] != '\n')
			abort_prog(buf);
		if (++letter > 'Z')
			abort_prog(buf);
		create_list(tetrominoes, letter, buf);
		if (read(fd, buf, 1))
			if (buf[0] != '\n')
				abort_prog(buf);
	}
	if (ret == 0 && (buf[0] == '\n' || buf[0] == '\0'))
		abort_prog(buf);
	free(buf);
}
