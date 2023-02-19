/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:42:32 by rafaemar          #+#    #+#             */
/*   Updated: 2023/02/19 20:37:47 by rafaemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	check_alone(int i, int **tab, int line, int col);
int	nbr_seen_left(int **tab, int line, int col, int val);
int	nbr_seen_right(int **tab, int line, int col, int val);
int	nbr_seen_up(int **tab, int line, int col, int val);
int	nbr_seen_down(int **tab, int line, int col, int val);

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 31)
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '4'))
			return (0);
		i++;
	}
	return (1);
}

int	check_nbr(int i, int **tab, int *line_col, int **hints)
{
	int	line;
	int	col;

	line = line_col[0];
	col = line_col[1];
	if (check_alone(i, tab, line, col))
	{
		if (hints[0][col] != nbr_seen_up(tab, line, col, i) && line == 3)
			return (0);
		if (hints[1][col] != nbr_seen_down(tab, line, col, i) && line == 3)
			return (0);
		if (hints[2][line] != nbr_seen_left(tab, line, col, i) && col == 3)
			return (0);
		if (hints[3][line] != nbr_seen_right(tab, line, col, i) && col == 3)
			return (0);
		return (1);
	}
	return (0);
}

int	*reduct(int line, int col)
{
	int	*line_col;

	line_col = (int *)malloc(8);
	line_col[0] = line;
	line_col[1] = col;
	return (line_col);
}

int	**ft_backtrack(int **tab, int line, int col, int **hints)
{
	static int	finish = 0;
	int			i;

	if (col == 4)
	{
		line ++;
		col = 0;
	}
	i = 1;
	while (i < 5 && (! finish))
	{
		if (check_nbr(i, tab, reduct(line, col), hints))
		{
			tab[line][col] = i;
			if (line == 3 && col == 3)
				finish = 1;
			else
				ft_backtrack(tab, line, col + 1, hints);
		}
		i++;
	}
	if (! finish)
		tab[line][col] = 0;
	return (tab);
}
