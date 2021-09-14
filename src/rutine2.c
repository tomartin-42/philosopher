#include "philo.h"

// this funtion gestion the fork keep
void get_fork1(t_philo *philo)
{
	uint64_t ini;
	
	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[0]] = KEEP;
	if(philo->table->banquet)
	printf("[%8lu] %d take fork %d\n", ini, philo->ph_name, philo->fork[0]);
	//ini = get_t(philo->table->str_time);
	//philo->table->forks[philo->fork[1]] = KEEP;
	//printf("[%8lu] %d take fork %d\n", ini, philo->ph_name, philo->fork[1]);
}

void get_fork2(t_philo *philo)
{
	uint64_t ini;
	
	//ini = get_t(philo->table->str_time);
	//philo->table->forks[philo->fork[0]] = KEEP;
	//printf("[%8lu] %d take fork %d\n", ini, philo->ph_name, philo->fork[0]);
	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[1]] = KEEP;
	if(philo->table->banquet)
	printf("[%8lu] %d take fork %d\n", ini, philo->ph_name, philo->fork[1]);
}
// this funtion gestion the fork drop 
void drop_fork1(t_philo *philo)
{
	uint64_t ini;

	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[0]] = FREE;
	if(philo->table->banquet)
	printf("[%8lu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[0]);
	//ini = get_t(philo->table->str_time);
	//philo->table->forks[philo->fork[1]] = FREE;
	//printf("[%8lu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[1]);
}

void drop_fork2(t_philo *philo)
{
	uint64_t ini;

	//ini = get_t(philo->table->str_time);
	//philo->table->forks[philo->fork[0]] = FREE;
	//printf("[%8lu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[0]);
	ini = get_t(philo->table->str_time);
	philo->table->forks[philo->fork[1]] = FREE;
	if(philo->table->banquet)
	printf("[%8lu] %d drop fork %d\n", ini, philo->ph_name, philo->fork[1]);
}

void	rutine_detach(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
	//	pthread_detach(philo->table->philo[i].thread);
//		pthread_join(philo->table->philo[i].thread, NULL);
		i++;
	}
}
