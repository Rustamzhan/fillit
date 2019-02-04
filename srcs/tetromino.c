/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:09:32 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 15:00:17 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*create_tetromino(char letter, t_point **positions)
{
	t_tetromino	*result;
	int			i;

	if (!(result = (t_tetromino *)malloc(sizeof(t_tetromino))))
		return (NULL);
	result->letter = letter;
	result->shape = positions;
	if (!(result->start = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	result->start->x = 0;
	result->start->y = 0;
	result->height = 0;
	result->width = 0;
	i = 0;
	while (i < TETR_SIZE)
	{
		if (result->shape[i]->x > result->width)
			result->width = result->shape[i]->x;
		if (result->shape[i]->y > result->height)
			result->height = result->shape[i]->y;
		i++;
	}
	return (result);
}
