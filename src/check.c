/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:09:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/05 19:24:56 by tomartin         ###   ########.fr       */
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

int	check(int argc, char **argv)
{
	int	check;
	int	check2;

	check = 0;
	if (argc > 6 || argc < 5)
	{
		printf("Error: number of arguments incorrect\n");
		check = 1;
	}
	check2 = check_characters(argv);
	return (check + check2);
}
