/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:09:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/15 11:38:06 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_characters(char **argv)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	check = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error: character incorrect in argument\n");
				check = 1;
			}
			j++;
		}
		i++;
	}
	return (check);
}

static int	check_n_max_philo(char **argv)
{
	int	check;
	int	philos;

	check = 0;
	philos = ft_atoi(argv[1]);
	if (philos > 200)
	{
		printf("Error: too much philos\n");
		check = 1;
	}
	return (check);
}

int	check(int argc, char **argv)
{
	int	check;
	int	check2;
	int	check3;

	check = 0;
	if (argc > 6 || argc < 5)
	{
		printf("Error: number of arguments incorrect\n");
		check = 1;
	}
	check2 = check_characters(argv);
	check3 = check_n_max_philo(argv);
	return (check + check2 + check3);
}
