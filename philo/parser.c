/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:05:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/09 23:32:14 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	ft_atoi(t_string str)
{
	unsigned int	num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
			i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num);
}

bool	check_args(int argc, t_string *argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (error_fn(ARGS_ERR), false);
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo < 1 || data->nb_philo > 200)
		return (error_fn(ARGS_ERR), false);
	data->die_time = ft_atoi(argv[2]);
	if (data->die_time < 60)
		return (error_fn(ARGS_ERR), false);
	data->eat_time = ft_atoi(argv[3]);
	if (data->eat_time < 60)
		return (error_fn(ARGS_ERR), false);
	data->sleep_time = ft_atoi(argv[4]);
	if (data->sleep_time < 60)
		return (error_fn(ARGS_ERR), false);
	if (argc == 6)
	{
		data->nb_eat = ft_atoi(argv[5]);
		if (data->nb_eat < 1)
			return (error_fn(ARGS_ERR), false);
	}
	else
		data->nb_eat = 0;
	return (true);
}
