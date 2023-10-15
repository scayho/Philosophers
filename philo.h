/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:37 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/06 22:54:45 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data{
	char					*smito;
	int						nb_philo;
	long long				tdie;
	int						teat;
	int						tsleep;
	int						nbeat;
	pthread_mutex_t			*forks;
	int						maxeat;
	int						samy;
	int						reste;
	int						death;
	int						start;
	pthread_t				*th;
	int						close;
	pthread_t				watcher;
	struct philo			*philo;
	pthread_mutex_t			ccall;
	pthread_mutex_t			samyyy;
}		t_data;

typedef struct philo
{
	int						index;
	int						eated;
	int						maxeated;
	int						nbeat;
	int						death;
	long long				start;
	int						teat;
	int						total;
	long long				snak;
	pthread_mutex_t			*shopsticks;
	pthread_mutex_t			*rshopsticks;
	pthread_mutex_t			*call;
	t_data					*asgard;
}	t_philo;

// typedef struct s_philo
// {

// }	t_philo;

int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putstr(char *str);
int			ft_strlen(char	*str);
int			ft_atoi(const char *str);
int			ft_isdigit(char	*str);
void		*philothing(void	*ptr);
void		peating(t_philo	*philo);
void		eating(t_philo	*philo);
void		shareshop(t_philo *philo, int i);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		printing(char	*str, t_philo *philo, int i);
void		dormir(long long nb);
long long	wakt(void);
void		chinigami(t_data *midgard);
int			parsing(int arc, char	**arv, t_data *midgard);
int			start_philo(t_data *midgard);
long long	wakt(void);

#endif
