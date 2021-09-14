#include "philo.h"

void	check_live(t_philo *philo)
{
	int 		i;
	uint64_t	ac_t;
	t_philo		aux_p;

	ac_t = get_t(philo->table->str_time);
	i = 0;
	while (i < philo->table->n_philos)
	{
		aux_p = philo->table->philo[i];
		if (ac_t > aux_p.t_lastacc && ac_t - aux_p.t_lastacc > aux_p.table->t_death)
		{
		/*	printf("p_name %d\n", aux_p.ph_name);
			printf("acc._t %lu\n", ac_t);
			printf("l_eat  %lu\n", aux_p.t_lastacc);
			printf("t_death %lu\n", aux_p.table->t_death);
			printf("_____________________\n"); */
			if(aux_p.table->banquet)
			{
				aux_p.table->banquet = false;
				printf("[%8lu] %d died\n", ac_t, philo->ph_name);
			}
			//paint ("died 💀💀💀", &aux_p);
	//		exit(0);
		//	printf("[%8lu] %d died\n", ac_t, philo->table->philo[i].ph_name);
			rutine_detach(&aux_p);
		}
		i++;
	}
}
	
void	paint(char *str, t_philo *philo)
{
	uint64_t	ac_t;

	ac_t = get_t(philo->table->str_time);
//	if(philo->table->banquet == true)
//	{
		if (philo->table->banquet)
			printf("[%8lu] %d %s\n", ac_t, philo->ph_name, str);
//	}
}
