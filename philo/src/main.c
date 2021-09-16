/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:48:44 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/16 07:38:34 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	only_one(t_table *table)
{
	printf("[%8d] %d take fork %d\n", 0, 1, 0);
	usleep(table->t_death);
	printf("[%8llu] %d died 💀 ☠️  👻\n", table->t_death, 1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!check(argc, argv))
	{
		ini_table(&table, argc, argv);
		if (table.n_philos == 1)
		{
			only_one(&table);
		}
		else
		{
			init_banquet(&table);
			free(table.forks);
			free(table.philo);
		}
	}
	return (0);
}
