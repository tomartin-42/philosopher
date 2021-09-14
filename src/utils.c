/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:19:02 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/11 15:31:45 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	int			neg;
	long long	resp;

	i = 0;
	resp = 0;
	neg = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resp = resp * 10 + str[i] - '0';
		i++;
		if ((resp * neg) > INT_MAX)
			return (-1);
		if ((resp * neg) < INT_MIN)
			return (0);
	}
	return (resp * neg);
}

void print_tb(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
	printf("ph num= %d\n", table->philo[i].n_filo);
	printf("ph name= %d\n", table->philo[i].ph_name);
	printf("ph live= %d\n", table->philo[i].live);
	printf("ph forks[0]= %d - %d\n", table->philo[i].fork[0], table->forks[table->philo[i].fork[0]]);
	printf("ph forks[1]= %d - %d\n", table->philo[i].fork[1], table->forks[table->philo[i].fork[1]]);
	printf("-----------------%d--------------------\n", i);
	i++;
	}
}

/*void init_philo(t_table *table)
{
	int	i;
	t_philo *aux;

	aux = table->philo;	
	i = 0;
	while (i < table->n_philos)
	{
		table->philo->n_filo = i;
		table->philo->ph_name = i + 1;
		table->philo->live = LIVE;
		if (i == table->n_philos - 1)
		{
			table->philo->fork[0] = i; 
			table->philo->fork[1] = 0; 
		}
		else
		{
			table->philo->fork[0] = i; 
			table->philo->fork[1] = i + 1; 
		}
		table->philo += 1;
		i++;
	}
		table->philo = aux;
		print_tb(table);
}*/
