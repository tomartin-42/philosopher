/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:27:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/15 09:45:33 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Function to star one thread per philo. Initialize the start time 
//to use to reference to check get_t function.
void init_banquet (t_table *table)
{
	int	i;

	i = 0;
	table->banquet = true;
	table->str_time = start_time();
	while (i < table->n_philos)
	{
		table->philo[i].t_lastacc = 0;
		i += 1;
	}
	i = 0;
	while (i < table->n_philos)
	{
		pthread_create(&table->philo[i].thread, NULL, rutine, &table->philo[i]);
		i += 2;
		usleep(210 - table->n_philos);
	}
	i = 1;
	while (i < table->n_philos)
	{
		pthread_create(&table->philo[i].thread, NULL, rutine, &table->philo[i]);
		i += 2;
		usleep(210 - table->n_philos);
	}
	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}

// Rutine to inicialice the philo's ritines. Need initialize the value of
// t_lastacc to check the time in to eats.
void	*(rutine(void *arg))
{
	t_philo *aux_p;

	aux_p = arg;
	while (aux_p->table->banquet)
	{
			eat_rutine(aux_p);
			sleep_rutine(aux_p);
			think_rutine(aux_p);

	}
	return (0);
}

// Eat rutine. In this rutine the philo get forks and check if is
// death(if time to start eat is over t_death cange live state to DEATH). 
void	eat_rutine(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	get_fork1(philo);
	pthread_mutex_lock(philo->p_mutex);
	get_fork2(philo);
	philo->lass_acc = 'E';
	philo->t_lastacc = get_t(philo->table->str_time); //get time to start eat
	philo->n_eat -= 1;
	paint("is eating 🍗 🍖 🦴", philo);
	check_n_eats(philo);
	pause_t(philo->table->t_eat, philo);
	drop_fork1(philo);
	pthread_mutex_unlock(&philo->mutex);
	drop_fork2(philo);
	pthread_mutex_unlock(philo->p_mutex);
}

void	sleep_rutine(t_philo *philo)
{
	philo->lass_acc = 'S';
	paint("is sleeping 🌙 🛏  🛌", philo);
	pause_t(philo->table->t_dream, philo);
}

void	think_rutine(t_philo *philo)
{
	philo->lass_acc = 'T';
	paint("is thinking 🤯 🤦🏻‍♂️ 🙅🏻‍♂️", philo);
}
