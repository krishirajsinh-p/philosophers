/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:05:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/06/27 04:53:32 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, t_string argv[])
{
	t_data	data;

	if (check_args(argc, argv, &data) == false)
		return (1);
	
	//check if no_of_philo > 0, check if time_to_die >= time_to_eat + time_to_sleep
	return (0);
}

//replace wildcard with filenames in makefile