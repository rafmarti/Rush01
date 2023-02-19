/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:41:08 by rafaemar          #+#    #+#             */
/*   Updated: 2023/02/19 20:44:46 by rafaemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	check_alone(int i, int **tab, int line, int col)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (tab[line][x] == i || tab[x][col] == i)
			return (0);
		x ++;
	}
	return (1);
}

int	nbr_seen_left(int **tab, int line, int col, int val)
{
	int	i;
	int	max;
	int	nb;

	nb = 0;
	max = 0;
	i = 0;
	while (i < 4 && i >= 0)
	{
		if (i == col)
			tab[line][i] = val;
		if (tab[line][i] > max)
		{
			max = tab[line][i];
			nb ++;
		}
		i++;
	}
	return (nb);
}

int	nbr_seen_right(int **tab, int line, int col, int val)
{
	int	i;
	int	max;
	int	nb;

	nb = 0;
	max = 0;
	i = 3;
	while (i < 4 && i >= 0)
	{
		if (i == col)
			tab[line][i] = val;
		if (tab[line][i] > max)
		{
			max = tab[line][i];
			nb ++;
		}
		i--;
	}
	return (nb);
}

int	nbr_seen_up(int **tab, int line, int col, int val)
{
	int	i;
	int	max;
	int	nb;

	nb = 0;
	max = 0;
	i = 0;
	while (i < 4 && i >= 0)
	{
		if (i == line)
			tab[i][col] = val;
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			nb ++;
		}
		i++;
	}
	return (nb);
}

int	nbr_seen_down(int **tab, int line, int col, int val)
{
	int	i;
	int	max;
	int	nb;

	nb = 0;
	max = 0;
	i = 3;
	while (i < 4 && i >= 0)
	{
		if (i == line)
			tab[i][col] = val;
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			nb ++;
		}
		i--;
	}
	return (nb);
}
