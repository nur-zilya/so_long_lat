/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:32 by hfast             #+#    #+#             */
/*   Updated: 2022/04/01 14:44:10 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_steps(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static char	*ft_cpychr(long a, char *it, int i)
{
	if (a == 0)
	{
		it[0] = '0';
		return (it);
	}
	if (a < 0)
	{
		it[0] = '-';
		a *= -1;
	}
	while (a > 0)
	{
		it[i] = a % 10 + '0';
		a /= 10;
		i--;
	}
	return (it);
}

char	*ft_itoa(int n)
{
	char	*it;
	long	a;
	int		i;

	a = n;
	i = ft_steps(a);
	it = (char *)malloc(sizeof(char) * (i + 1));
	if (it == 0)
		return (0);
	it[i] = '\0';
	i--;
	ft_cpychr(a, it, i);
	return (it);
}
