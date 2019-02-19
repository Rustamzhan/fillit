/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:37:41 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:20:56 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			search_min_y(char *buf)
{
	int	min_y;
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == FULL)
		{
			min_y = ((i > TETR_SIZE) ? i % LINE_LEN : i);
			while (buf[++i] != '\0')
			{
				if (buf[i] == FULL)
				{
					if ((i / LINE_LEN) > 0)
						min_y = (((i % LINE_LEN) < min_y) ?
								(i % LINE_LEN) : min_y);
					else
						min_y = ((i < min_y) ? i : min_y);
				}
			}
		}
		i++;
	}
	return (min_y);
}

static int			search_min_x(char *buf)
{
	int n;
	int	i;
	int	min_x;

	n = 0;
	i = 0;
	min_x = 0;
	while (buf[i] != '\0')
	{
		n += ((buf[i] == '\n') ? 1 : 0);
		if (buf[i++] == FULL)
		{
			min_x = n;
			return (min_x);
		}
	}
	return (min_x);
}

static t_point		**create_positions(char *buf)
{
	int		min_x;
	int		min_y;
	int		i;
	int		j;
	t_point	**positions;

	i = -1;
	j = -1;
	if (!(positions = (t_point **)malloc(TETR_SIZE * sizeof(t_point))))
		return (NULL);
	min_x = search_min_x(buf);
	min_y = search_min_y(buf);
	while (buf[++i] != '\0')
	{
		if (buf[i] == FULL)
		{
			if (!(positions[++j] = (t_point *)malloc(sizeof(t_point))))
				return (NULL);
			positions[j]->x = i / LINE_LEN - min_x;
			positions[j]->y = ((i > TETR_SIZE) ? (i % LINE_LEN - min_y) :
					(i - min_y));
		}
	}
	return (positions);
}

t_tetromino			*create_content(char letter, char *buf)
{
	t_tetromino	*new;

	new = create_tetromino(letter, create_positions(buf));
	return (new);
}
