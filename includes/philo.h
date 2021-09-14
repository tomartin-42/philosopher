/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:44:17 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/14 11:57:27 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

# define FREE 0
# define KEEP 1
# define LIVE 1
# define DEATH 0

struct			s_table;

typedef struct s_philo {
	int					n_filo;
	int					ph_name;
	bool				live;
	int					fork[2];
	char				lass_acc;
	uint64_t			t_lastacc;
	int					n_eat;
	struct s_table		*table;
	pthread_t			thread;
	pthread_mutex_t 	mutex;
	pthread_mutex_t 	mutex2;
	pthread_mutex_t 	*p_mutex;
} t_philo;
	
typedef	struct s_table {
	uint64_t	str_time;
	int			*forks;
	int			n_philos;
	uint64_t	t_death;
	uint64_t	t_eat;
	uint64_t	t_dream;
	bool		banquet;
	t_philo		*philo;
} t_table;

int	ft_atoi(char *s);

int	check(int argc, char **argv);

void ini_table(t_table *table, int argc, char **argv);
void init_philo(t_table *table);
void init_banquet(t_table *table);

void	*rutine(void *arg);
void	eat_rutine(t_philo *philo);
void	sleep_rutine(t_philo *philo);
void	think_rutine(t_philo *philo);
void	get_fork1(t_philo *philo);
void	get_fork2(t_philo *philo);
void	drop_fork1(t_philo *philo);
void	drop_fork2(t_philo *philo);

uint64_t	start_time(void);
uint64_t	get_t(uint64_t start);
void		pause_t(uint64_t pause, t_philo *philo);

void	print_tb(t_table *table);
void	paint(char *str, t_philo *philo);
void	check_live(t_philo *philo);
void	rutine_detach(t_philo *philo);

#endif
