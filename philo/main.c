/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:05:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/09 23:34:03 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, t_string argv[])
{
	t_data	data;

	if (check_args(argc, argv, &data) == false)
		return (EXIT_FAILURE);
	if (init_data(&data) == false)
		return (EXIT_FAILURE);
	if (create_threads(&data) == false)
		return (EXIT_FAILURE);
	if (join_threads(&data) == false)
		return (EXIT_FAILURE);
	if (free_data(&data) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
