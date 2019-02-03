/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:07:29 by astanton          #+#    #+#             */
/*   Updated: 2019/01/29 17:56:22 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 20
#include <unistd.h>
#include <stdio.h>
#include "fillit.h"

int		check_for_touch(char *buf, int i)
{
	int nbr;

	nbr = 0;
	nbr += ((buf[i + 1] == '#') ? 1 : 0);
	if (i < 15)
		nbr += ((buf[i + 5] == '#') ? 1 : 0);
	if (i > 0)
		nbr += ((buf[i - 1] == '#') ? 1 : 0);
	if (i > 4)
		nbr += ((buf[i - 5] == '#') ? 1 : 0);
	return (nbr);
}

int		check_buf(char *buf)
{
	int i;
	int lines;
	int nbr_points;
	int nbr_sharps;
	int	nbr_touch;

	i = -1;
	lines = 0;
	nbr_points = 0;
	nbr_sharps = 0;
	nbr_touch = 0;
	while (buf[++i] != '\0')
	{
		if ((buf[i] != '#' && buf[i] != '.' && buf[i] != '\n' && buf[i] != '\0')
				|| lines++ > 5)
			return (1);
		lines = ((buf[i] == '\n') ? 0 : lines);
		if (buf[i] == '#')
		{
			nbr_sharps++;
			nbr_touch += check_for_touch(buf, i);
		}
		nbr_points += ((buf[i] == '.') ? 1 : 0);
	}
	return ((nbr_sharps != 4 || nbr_points != 12 || nbr_touch < 5) ? 1 : 0);
}

void	failed_check(int i)
{
	if (i == 1)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

t_list	*create_list(t_list **lst, int letter, char *buf)
{
	t_list	*current;
	t_list	*new;

	current = *lst;
	if (!*lst)
	{
		*lst = ft_lstnew(NULL, 0);
		current = *lst;
		current->content = create_one_content(letter, buf);
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new = ft_lstnew(NULL, 0);
		current->next = new;
		current = current->next;
		current->content = create_one_content(letter, buf);
	}
	return (*lst);
}

void	validating_file(int fd, t_list **lst)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				letter;

	if (fd < 0 || read(fd, buf, 0) < 0)
		failed_check(1);
	letter = 'A' - 1;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (check_buf(buf))
			failed_check(1);
		if (buf[ret - 1] != '\n')
			failed_check(1);
		if (++letter > 'Z')
			failed_check(1);
		*lst = create_list(lst, letter, &buf[0]);
		if (read(fd, buf, 1))
			if (buf[0] != '\n')
				failed_check(1);
	}
	if (ret == 0 && (buf[0] == '\n' || buf[0] == '\0'))
		failed_check(1);
}
