/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:09:32 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 22:32:46 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*create_tetromino_1(t_tetromino *result)
{
	int	i;

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

t_tetromino	*create_tetromino(char letter, t_point **positions)
{
	t_tetromino	*result;
	int			i;

	if (!(result = malloc(sizeof(t_tetromino))))
		return (NULL);
	result->letter = letter;
	if (!(result->shape = malloc(4 * sizeof(t_point*))))
		return (NULL);
	i = -1;
	while (++i < 4)
		result->shape[i] = positions[i];
	if (!(result->start = malloc(sizeof(t_point))))
		return (NULL);
	result->start->x = 0;
	result->start->y = 0;
	result->height = 0;
	result->width = 0;
	result = create_tetromino_1(result);
	return (result);
}
