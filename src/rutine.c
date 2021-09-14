/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:27:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/14 12:14:36 by tomartin         ###   ########.fr       */
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
//		table->philo[i].t_lastacc = get_t(table->str_time);
		pthread_create(&table->philo[i].thread, NULL, rutine, &table->philo[i]);
		//pause_t(0, &table->philo[i]);
		i += 2;
		usleep(200 - table->n_philos);
	}
	i = 1;
	while (i < table->n_philos)
	{
//		table->philo[i].t_lastacc = get_t(table->str_time);
		pthread_create(&table->philo[i].thread, NULL, rutine, &table->philo[i]);
		i += 2;
	//	usleep(table->n_philos);
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
	//while (1)
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
	//uint64_t ini;

	//check_live(philo);
	pthread_mutex_lock(&philo->mutex);
	get_fork1(philo);
	pthread_mutex_lock(philo->p_mutex);
	get_fork2(philo);
	philo->lass_acc = 'E';
	philo->t_lastacc = get_t(philo->table->str_time); //get time to start eat
	philo->n_eat -= 1;
	//ini = get_t(philo->table->str_time);
	//check_death(philo, ini);
	paint("is eating", philo);
	//printf("[%8ld] %d eating\n", ini, philo->ph_name);
	pause_t(philo->table->t_eat, philo);
	drop_fork1(philo);
	pthread_mutex_unlock(&philo->mutex);
	drop_fork2(philo);
	pthread_mutex_unlock(philo->p_mutex);
	//check_live(philo);
}

void	sleep_rutine(t_philo *philo)
{
	//uint64_t ini;

	//check_live(philo);
	philo->lass_acc = 'S';
	//ini = get_t(philo->table->str_time);
	paint("is sleeping", philo);
	//printf("[%8ld] %d sleeping\n", ini, philo->ph_name);
	pause_t(philo->table->t_dream, philo);
	//check_live(philo);
}

void	think_rutine(t_philo *philo)
{
	//uint64_t ini;

	//check_live(philo);
	philo->lass_acc = 'T';
	//ini = get_t(philo->table->str_time);
	paint("is thinking", philo);
	//printf("[%8ld] %d thinking\n", ini, philo->ph_name);
	//check_live(philo);
}
