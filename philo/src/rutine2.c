/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:03:02 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/16 07:31:16 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// this funtion gestion the fork keep
void	get_fork1(t_philo *philo)
{
	uint64_t	ini;

	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[0]] = KEEP;
	if (philo->table->banquet)
		printf("[%8llu] %d take fork %d\n", ini, philo->ph_name, philo->fork[0]);
}

void	get_fork2(t_philo *philo)
{
	uint64_t	ini;

	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[1]] = KEEP;
	if (philo->table->banquet)
		printf("[%8llu] %d take fork %d\n", ini, philo->ph_name, philo->fork[1]);
}

// this funtion gestion the fork drop 
void	drop_fork1(t_philo *philo)
{
	uint64_t	ini;

	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[0]] = FREE;
	if (philo->table->banquet)
		printf("[%8llu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[0]);
}

void	drop_fork2(t_philo *philo)
{
	uint64_t	ini;

	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[1]] = FREE;
	if (philo->table->banquet)
		printf("[%8llu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[1]);
}
