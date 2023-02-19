/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:13:00 by rafaemar          #+#    #+#             */
/*   Updated: 2023/02/19 20:51:44 by rafaemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	**ft_backtrack(int **tab, int line, int col, int **hint);
int	check_input(char *str);
int	check_puzzle(int **tab, int **hints);

int	**make_tab(void)
{
	int	**tab;
	int	i;

	tab = (int **)malloc(4 * sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tab[i] = (int *)malloc(4 * sizeof(int));
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}

int	**fill_tab(int **tab, char *str)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			tab[row][col] = str[i] - '0';
			i++;
			col++;
		}
		row++;
	}
	return (tab);
}

void	print_tab(int **tab)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp = tab[i][j] + 48;
			write (1, &temp, 1);
			write (1, " ", 1);
			j++;
		}
		i++;
		write (1, "\n", 1);
	}
}

char	*str_normalize(char *str)
{
	char	*str_result;
	int		i;
	int		j;	

	str_result = (char *)malloc(17);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str_result[j] = str[i];
			j++;
		}
		i++;
	}
	str_result[16] = 0;
	return (str_result);
}

int	main(int argc, char **argv)
{
	int		**hints;
	int		**result;
	char	*input_str;

	if (argc == 2 && check_input(argv[1]) == 1)
	{
		hints = make_tab();
		result = make_tab();
		input_str = str_normalize(argv[1]);
		result = fill_tab(result, "0000000000000000");
		hints = fill_tab(hints, input_str);
		result = ft_backtrack(result, 0, 0, hints);
		if (!(result[0][0] == 0))
			print_tab(result);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
