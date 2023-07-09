/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:08:04 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/09 20:15:24 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->left_fork);
	print(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print(philo, FORK);
	print(philo, EAT);	
	philo->last_meal = current_time();
	ft_usleep(data->eat_time, philo);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	routine(t_philo *philo)
{
	if (philo->id % 2)
		ft_usleep(philo->data->eat_time, philo);
	while (philo->data->all_alive)
	{
		eat(philo);
		if (philo->data->meals_done)
			break ;
		print(philo, SLEEP);
		ft_usleep(philo->data->sleep_time, philo);
		print(philo, THINK);
	}
}

void	death_checker(t_data *d, t_philo *p)
{
	unsigned int i;

	while (d->meals_done == false)
	{
		i = 0;
		while (i < d->nb_philo && d->all_alive)
		{
			d->all_alive = (current_time() - p[i].last_meal) <= d->die_time;
			if (d->all_alive == false)
				print(&p[i], DIED);
			ft_usleep(100, &p[i]);
			i++;
		}
		if (d->all_alive == false)
			break ;
		i = 0;
		while (d->nb_eat != 0 && i < d->nb_philo && p[i].nb_meal >= d->nb_eat)
			i++;
		if (i == d->nb_philo)
			d->meals_done = 1;
	}
}
