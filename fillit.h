/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:30:32 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 22:48:09 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TETR_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

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
void			print_fill_board(char **board, t_list *lst, int init_size);
void			print_last(char **board, int init_size);
void			ft_clear_2d_arr(void **arr);
void			failed_check(int i);
void			search_min(int i, int *min_x, int *min_y, char *buf);
void			change_point(t_point *a, int x, int y);
void			validating_file(int fd, t_list **lst);
int				solve(t_list *tetrominos);
int				ft_sqrt_up(int n);
int				ft_lst_len(t_list *lst);
int				check_for_touch(char *buf, int i);
int				check_buf(char *buf);
t_list			*create_list(t_list **lst, int letter, char *buf);
t_tetromino		*create_tetromino(char letter, t_point **positions);
t_tetromino		*create_one_content(char letter, char *buf);
t_point			**create_positions(char *buf);
t_point			*create_point(int x, int y);
t_point			*sum_points(int x, int y, t_point *a);

#endif
