/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:32:30 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/14 12:18:14 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	start_time(void)
{
	uint64_t		time;
	struct timeval	aux_time;

	gettimeofday(&aux_time, NULL);
	time = (uint64_t)((aux_time.tv_sec * 1000) + (aux_time.tv_usec / 1000));
	return (time);
}

uint64_t	get_t(uint64_t start)
{
	uint64_t		time;
	struct timeval	aux_time;

	gettimeofday(&aux_time, NULL);
	time = (uint64_t)((aux_time.tv_sec * 1000) + (aux_time.tv_usec / 1000));

	return (time - start);
}

void	pause_t(uint64_t pause, t_philo *philo)
{
	uint64_t		end_t;
	struct timeval	aux_time;

	gettimeofday(&aux_time, NULL);
	end_t = (uint64_t)((aux_time.tv_sec * 1000) 
			+ (aux_time.tv_usec / 1000)) + pause;
	while (1)
	{
//		pthread_mutex_lock(&philo->mutex2);
		check_live(philo);
//		pthread_mutex_unlock(&philo->mutex2);
		usleep(philo->table->n_philos);
		//usleep(200);
		gettimeofday(&aux_time, NULL);
		if ((uint64_t)((aux_time.tv_sec * 1000) 
					+ (aux_time.tv_usec / 1000)) >= end_t)
			break ;
	}
}
