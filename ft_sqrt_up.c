/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:02:52 by astanton          #+#    #+#             */
/*   Updated: 2019/02/03 21:03:52 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_up(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i);
}