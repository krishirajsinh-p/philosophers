/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:06:03 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/10 02:13:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

# define ARGS_ERR 0
# define MALLOC_ERR 1
# define MUTEX_INIT_ERR 2
# define PTHREAD_CREATE_ERR 3
# define PTHREAD_JOIN_ERR 4
# define MUTEX_DESTROY_ERR 5

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef char *				t_string;
typedef unsigned long long	t_time;
typedef struct s_data		t_data;

typedef struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned int	nb_meal;
	t_time			last_meal;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	unsigned int	nb_philo;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	nb_eat;
	bool			all_alive;
	bool			meals_done;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_data;

//parser.c
bool			check_args(int argc, t_string *argv, t_data *data);

//init.c
bool			init_data(t_data *data);
bool			create_threads(t_data *data);

//philo.c
void			routine(t_philo *philo);
void			monitor(t_data *d, t_philo *p);

//free.c
bool			free_data(t_data *data);
bool			join_threads(t_data *data);

//utils.c
t_time			current_time(void);
void			ft_usleep(t_time sleep_time);
void			print(t_philo *philo, t_string str);
void			error_fn(unsigned short errorno);

#endif
