/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:10:09 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/15 11:18:25 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_eat_number(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 6)
	{	
		while (i < table->n_philos)
		{
			table->philo[i].n_eat = ft_atoi(argv[5]);
			i++;
		}
	}
	else
		table->philo[i].n_eat = -1;
}

static void	init_forks(int *forks, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		forks[i] = FREE;
		i++;
	}
}

static void	init_philo2(t_table *table, int i)
{
	table->philo[i].table = table;
	table->philo[i].n_filo = i;
	table->philo[i].ph_name = i + 1;
	table->philo[i].live = LIVE;
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		init_philo2(table, i);
		if (i == table->n_philos - 1)
		{
			table->philo[i].fork[0] = i;
			table->philo[i].fork[1] = 0;
			table->philo[i].p_mutex = &table->philo[0].mutex;
			pthread_mutex_init(&table->philo[i].mutex, NULL);
			pthread_mutex_init(&table->philo[i].mutex2, NULL);
		}
		else
		{
			table->philo[i].fork[0] = i;
			table->philo[i].fork[1] = i + 1;
			table->philo[i].p_mutex = &table->philo[i + 1].mutex;
			pthread_mutex_init(&table->philo[i].mutex, NULL);
		}
		i++;
	}
}

void	ini_table(t_table *table, int argc, char **argv)
{
	table->n_philos = ft_atoi(argv[1]);
	table->forks = (int *) malloc(sizeof (int) * table->n_philos);
	init_forks (table->forks, table->n_philos);
	table->philo = (t_philo *) malloc(sizeof (t_philo) * table->n_philos);
	init_philo(table);
	table->t_death = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_dream = ft_atoi(argv[4]);
	add_eat_number(table, argc, argv);
}
