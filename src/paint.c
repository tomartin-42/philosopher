/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:21:19 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/15 11:54:50 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_live(t_philo *philo)
{
	int			i;
	uint64_t	ac_t;
	t_philo		aux_p;

	ac_t = get_t(philo->table->str_time);
	i = 0;
	while (i < philo->table->n_philos)
	{
		aux_p = philo->table->philo[i];
		if (ac_t > aux_p.t_lastacc && ac_t - aux_p.t_lastacc
			> aux_p.table->t_death)
		{
			if (aux_p.table->banquet)
			{
				aux_p.table->banquet = false;
				printf("[%8llu] %d died 💀 ☠️  👻\n", ac_t, philo->ph_name);
			}
		}
		i++;
	}
}

void	paint(char *str, t_philo *philo)
{
	uint64_t	ac_t;

	ac_t = get_t(philo->table->str_time);
	if (philo->table->banquet)
	{
		pthread_mutex_lock(&philo->mutex2);
		printf("[%8llu] %d %s\n", ac_t, philo->ph_name, str);
		pthread_mutex_unlock(&philo->mutex2);
	}
}

void	check_n_eats(t_philo *philo)
{
	if (philo->n_eat == 0)
		philo->table->banquet = false;
}
