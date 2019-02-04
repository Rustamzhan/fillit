/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:04:48 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 21:05:51 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_point(t_point *a, int x, int y)
{
	a->x = x;
	a->y = y;
}

t_point	*sum_points(int x, int y, t_point *a)
{
	t_point *sum;

	if (!(sum = malloc(sizeof(t_point))))
		return (NULL);
	sum->x = a->x + x;
	sum->y = a->y + y;
	return (sum);
}

t_point	*create_point(int x, int y)
{
	t_point *new;

	if (!(new = malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
