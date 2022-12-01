/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:21:45 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 18:32:47 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_c_t(t_t *t, int argc, char **argv)
{
	t->philo_n = ft_atoi(argv[1]);
	t->time_to_die = (long int) ft_atoi(argv[2]);
	t->time_to_eat = (long int) ft_atoi(argv[3]);
	t->time_to_sleep = (long int) ft_atoi(argv[4]);
	if (argc == 6)
		t->cycles = ft_atoi(argv[5]);
	else
		t->cycles = -1;
	if (t->philo_n < 0 || t->philo_n > 200 || t->time_to_die < 0 \
		|| t->time_to_eat < 0 || t->time_to_sleep < 0)
		return (1);
	t->dead_status = 0;
	t->philo_feeded = 0;
	pthread_mutex_init(&t->printf, NULL);
	pthread_mutex_init(&t->lock, NULL);
	pthread_mutex_init(&t->dead, NULL);
	return (0);
}

void	ft_c_forks(t_t *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_n)
	{
		pthread_mutex_init(&t->forks[i], NULL);
	}
	i = 0;
	t->phs[i].l_fork = &t->forks[0];
	t->phs[i].r_fork = &t->forks[t->philo_n - 1];
	i = 1;
	while (i < t->philo_n)
	{
		t->phs[i].l_fork = &t->forks[i];
		t->phs[i].r_fork = &t->forks[i - 1];
		i++;
	}
}

void	ft_c_phs(t_t *t)
{
	int	i;

	i = 0;
	while (i < t->philo_n)
	{
		t->phs[i].t = t;
		t->phs[i].index = i + 1;
		t->phs[i].eat_count = 0;
		t->phs[i].time_to_die = t->time_to_die;
		t->phs[i].eating = 0;
		t->phs[i].detached = 0;
		pthread_mutex_init(&t->phs[i].lock, NULL);
		i++;
	}
}

int	ft_alloc(t_t *t)
{
	t->p_t = malloc (sizeof(pthread_t) * t->philo_n);
	if (!t->p_t)
		return (1);
	t->forks = malloc (sizeof(pthread_mutex_t) * t->philo_n);
	if (!t->forks)
		return (1);
	t->phs = malloc (sizeof(t_philo) * t->philo_n);
	if (!t->phs)
		return (1);
	return (0);
}

int	ft_constructor(t_t *t, int argc, char **argv)
{
	if (ft_c_t(t, argc, argv))
		return (1);
	if (ft_alloc(t))
		return (1);
	ft_c_forks(t);
	ft_c_phs(t);
	return (0);
}
