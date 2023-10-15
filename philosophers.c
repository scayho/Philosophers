/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:29:35 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/07 04:19:53 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	wakt(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	dormir(long long nb)
{
	long long	start;

	start = wakt ();
	while (wakt() - start <= nb)
	{
		usleep(100);
	}
}

void	printing(char	*str, t_philo *philo, int i)
{
	pthread_mutex_lock(philo->call);
	printf("{%lld} [%d] is %s\n", wakt() - philo->start, philo->index + 1, str);
	if (i == 1)
		pthread_mutex_unlock(philo->call);
}

int	launch(t_data	*midgard, int i, int nb)
{	
	while (i < nb)
	{
		if (pthread_mutex_init(&midgard->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	i = -1;
	while (++i < nb)
	{
		midgard->philo[i].shopsticks = &midgard->forks[i];
		if (i == nb - 1)
			midgard->philo[i].rshopsticks = &midgard->forks[0];
		else
			midgard->philo[i].rshopsticks = &midgard->forks[i + 1];
	}
	i = -1;
	while (++i < nb)
	{
		midgard->philo[i].snak = wakt();
		if (pthread_create(&midgard->th[i], NULL, \
			&philothing, &midgard->philo[i]) != 0)
			return (0);
		usleep(100);
	}
	return (1);
}

int	start_philo(t_data *midgard)
{
	int			i;
	int			nb;

	i = 0;
	if (pthread_mutex_init(&midgard->ccall, NULL) != 0)
		return (0);
	nb = midgard->nb_philo;
	midgard->th = malloc (sizeof(pthread_t) * midgard->nb_philo);
	if (!midgard->th)
		return (0);
	i = 0;
	if (!launch(midgard, i, nb))
		return (free(midgard->th), 0);
	i = 0;
	chinigami(midgard);
	while (i < midgard->nb_philo)
	{
		pthread_mutex_destroy(&midgard->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&midgard->ccall);
	return (1);
}
