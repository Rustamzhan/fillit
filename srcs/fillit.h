/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:30:32 by astanton          #+#    #+#             */
/*   Updated: 2019/02/04 21:18:31 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TETR_SIZE 4
# define LINE_LEN 5
# define FULL '#'
# define EMP '.'
# define BUFF_SIZE 20
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tetromino
{
	char	letter;
	t_point	**shape;
	t_point	*start;
	int		height;
	int		width;
}				t_tetromino;

void			print_board(int init_size, t_list *lst);
void			ft_clear_2d_arr(void **arr);
void			change_point(t_point *a, int x, int y);
void			validating_file(int fd, t_list **lst);
int				solve(t_list *tetrominos);
int				ft_sqrt_up(int n);
int				ft_lst_len(t_list *lst);
t_tetromino		*create_tetromino(char letter, t_point **positions);
t_tetromino		*create_content(char letter, char *buf);
t_point			*create_point(int x, int y);
t_point			*sum_points(int x, int y, t_point *a);

#endif
