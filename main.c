/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:39:49 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/07 04:14:43 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_data		*midgard;

	if (arc > 6 || arc < 5)
	{
		ft_putstr(" you better enter the arguments as follow : \n");
		ft_putstr(" {execute file} {number of philo} {time to die} ");
		ft_putstr("{time to eat} {time to sleep} ~ {number of meals} !\n");
		return (0);
	}
	midgard = malloc(sizeof(t_data));
	if (midgard == NULL)
		return (-1);
	if (!parsing(arc, arv, midgard))
		return (0);
	if (!start_philo(midgard))
		return (0);
	return (0);
}
