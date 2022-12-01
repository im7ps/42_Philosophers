/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:13:27 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:23:40 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<sys/time.h>
# include	<stdlib.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdarg.h>

# define TAKE_FORK "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DEAD "died"

struct	s_t;

typedef struct s_philo
{
	int				index;
	int				eat_count;
	int				eating;
	int				detached;
	pthread_t		t_vulture;
	long int		time_to_die;
	struct s_t		*t;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	lock;
}	t_philo;

typedef struct s_t
{
	int				philo_n;
	int				cycles;
	int				dead_status;
	int				philo_feeded;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		time_to_eat;
	long int		time_zero;
	pthread_t		*p_t;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf;
	pthread_mutex_t	lock;
	pthread_mutex_t	dead;
	t_philo			*phs;
}	t_t;

int			ft_printf(const	char *string, ...);
int			ft_putchar(const char c);
int			ft_putstr(char *string);
int			ft_print_int(long long int number);
int			ft_print_ul_int(unsigned long long int number);

int			ft_start_routine(t_t *t);
void		*ft_chef(void *t_p);
long int	ft_get_time(void);
int			ft_input_checker(int argc, char **argv);
int			ft_c_t(t_t *t, int argc, char **argv);
void		ft_c_forks(t_t *t);
void		ft_c_phs(t_t *t);
int			ft_alloc(t_t *t);
int			ft_constructor(t_t *t, int argc, char **argv);
void		*ft_start(void *philo_p);
void		ft_eating(t_philo *philo);
void		*ft_vulture(void *philo);
void		ft_take_forks(t_philo *philo);
void		ft_drop_forks(t_philo *philo);
int			ft_strcmp(char *str1, char *str2);
void		ft_write(char *str, t_philo *philo);
int			ft_usleep(useconds_t time);
int			ft_atoi(char *str);
int			ft_free_stuff(t_t *t);
int			ft_lonely_philo(t_philo *philo);
#endif