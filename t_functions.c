/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:43:38 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:31:45 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_chef(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	while (philo->t->dead_status == 0)
	{
		pthread_mutex_lock(&philo->t->lock);
		if (philo->t->philo_feeded >= philo->t->philo_n)
		{
			philo->t->dead_status = 1;
		}
		pthread_mutex_unlock(&philo->t->lock);
	}
	return ((void *)0);
}

void	*ft_vulture(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	while (philo->t->dead_status == 0)
	{
		pthread_mutex_lock(&philo->t->dead);
		if (ft_get_time() - philo->t->time_zero > philo->time_to_die \
			&& philo->eating == 0 && philo->t->dead_status != 1)
		{
			philo->t->dead_status = 1;
			ft_write(DEAD, philo);
		}
		pthread_mutex_unlock(&philo->t->dead);
	}
	return ((void *)0);
}

void	*ft_start(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	if (pthread_create(&philo->t_vulture, NULL, &ft_vulture, (void *)philo))
		return ((void *)0);
	while (philo->t->dead_status == 0)
	{
		ft_eating(philo);
		ft_write(THINKING, philo);
	}
	if (pthread_join(philo->t_vulture, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	ft_start_routine(t_t *t)
{
	int			i;
	pthread_t	t_chef;

	i = -1;
	t->time_zero = ft_get_time();
	if (t->cycles > 0)
	{
		if (pthread_create(&t_chef, NULL, &ft_chef, (void *)&t->phs[0]))
			return (1);
	}
	while (++i < t->philo_n)
	{
		if (pthread_create(&t->p_t[i], NULL, &ft_start, (void *)&t->phs[i]))
			return (1);
		usleep(30);
	}
	i = -1;
	while (++i < t->philo_n)
	{
		if (pthread_join(t->p_t[i], NULL))
			return (1);
	}
	return (0);
}
