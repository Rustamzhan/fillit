/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:00:36 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 21:02:14 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_lst_len(t_list *lst)
{
	t_list	*current;
	int		len;

	current = lst;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
