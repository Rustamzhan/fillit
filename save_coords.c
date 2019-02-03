/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:37:41 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 22:48:44 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		search_min(int i, int *min_x, int *min_y, char *buf)
{
	int n;

	n = 0;
	while (buf[++i] != '\0')
	{
		n += ((buf[i] == '\n') ? 1 : 0);
		if (buf[i] == '#')
		{
			*min_x = n;
			*min_y = ((i > 4) ? i % (n * 5) : i);
			while (buf[++i] != '\0')
			{
				n += ((buf[i] == '\n') ? 1 : 0);
				if (buf[i] == '#')
				{
					if (n > 0)
						*min_y = (((i % (5 * n)) < *min_y) ? (i % (5 * n)) :
								*min_y);
					else
						*min_y = ((i < *min_y) ? i : *min_y);
				}
			}
		}
	}
	return ;
}

t_point		**create_positions(char *buf)
{
	int		min_x;
	int		min_y;
	int		i;
	int		j;
	t_point	**positions;

	i = -1;
	j = -1;
	positions = malloc(4 * sizeof(t_point));
	search_min(i, &min_x, &min_y, buf);
	while (buf[++i] != '\0')
	{
		if (buf[i] == '#')
		{
			positions[++j] = malloc(sizeof(t_point));
			positions[j]->x = i / 5 - min_x;
			positions[j]->y = ((i > 4) ? (i % (i / 5 * 5) - min_y) :
					(i - min_y));
		}
	}
	return (positions);
}

t_tetromino	*create_one_content(char letter, char *buf)
{
	t_tetromino	*new;
	t_point		**positions;

	positions = create_positions(buf);
	new = create_tetromino(letter, positions);
	return (new);
}
