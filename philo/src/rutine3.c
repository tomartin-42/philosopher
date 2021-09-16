/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:47:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/15 10:56:23 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_odd(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_create(&table->philo[i].thread,
			NULL, rutine, &table->philo[i]);
		i += 2;
		usleep(210 - table->n_philos);
	}
}

void	start_even(t_table *table)
{
	int	i;

	i = 1;
	while (i < table->n_philos)
	{
		pthread_create(&table->philo[i].thread,
			NULL, rutine, &table->philo[i]);
		i += 2;
		usleep(210 - table->n_philos);
	}
}
