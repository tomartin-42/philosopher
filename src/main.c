/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:48:44 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/14 08:05:58 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!check(argc, argv))
	{
		ini_table(&table, argc, argv);
		init_banquet(&table);
		//while (1)
		//while (i < table.n_philos)
		//{	
		//	printf("hola\n");
		//	check_live(&table.philo[i]);
			//i++;
			//if (i == table.n_philos)
			//	i = 0;
		////}
	//	print_tb(&table);
	}
}
