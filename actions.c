/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:49:49 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 18:30:34 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_write(TAKE_FORK, philo);
	pthread_mutex_lock(philo->l_fork);
	ft_write(TAKE_FORK, philo);
	ft_write(EATING, philo);
	philo->eat_count++;
	if (philo->eat_count >= philo->t->cycles)
	{
		philo->t->philo_feeded++;
	}
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_write(SLEEPING, philo);
	ft_usleep(philo->t->time_to_sleep);
}

void	ft_eating(t_philo *philo)
{
	ft_take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die += ft_get_time() - philo->t->time_zero;
	ft_usleep(philo->t->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	ft_drop_forks(philo);
}
