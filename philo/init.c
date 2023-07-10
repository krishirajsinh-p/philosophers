/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 06:00:11 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/10 02:14:12 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_data *data)
{
	t_philo			*philo;
	unsigned int	i;

	philo = data->philo;
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		philo[i].nb_meal = 0;
		philo[i].data = data;
		i++;
	}
}

bool	init_data(t_data *data)
{
	unsigned int	i;

	data->all_alive = true;
	data->meals_done = false;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->forks == NULL)
		return (error_fn(MALLOC_ERR), false);
	i = 0;
	while (i < data->nb_philo)
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (error_fn(MUTEX_INIT_ERR), false);
	if (pthread_mutex_init(&data->print, NULL))
		return (error_fn(MUTEX_INIT_ERR), false);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (data->philo == NULL)
		return (error_fn(MALLOC_ERR), false);
	init_philos(data);
	return (true);
}

bool	create_threads(t_data *data)
{
	t_philo			*philo;
	unsigned int	i;

	philo = data->philo;
	i = 0;
	current_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)&routine, &philo[i]))
			return (error_fn(PTHREAD_CREATE_ERR), false);
		philo[i].last_meal = current_time();
		i++;
	}
	monitor(data, philo);
	return (true);
}
