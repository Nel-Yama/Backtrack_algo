/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:39:18 by nel-yama          #+#    #+#             */
/*   Updated: 2025/11/04 22:39:18 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_swap_chr(char *ch1, char *ch2)
{
	char tmp;

	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void	ft_sort_str(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i;
		while (s[j])
		{
			if (s[i] > s[j])
				ft_swap_chr(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void	ft_permutations(char *s, int idx)
{
	int	i;

	if (!s[idx])
	{
		puts(s);
		return ;
	}
	i = idx;
	while (s[i])
	{
		ft_sort_str(&s[idx]);
		ft_swap_chr(&s[idx], &s[i]);
		ft_permutations(s, idx + 1);
		ft_swap_chr(&s[i], &s[idx]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (2);
	ft_sort_str(av[1]);
	ft_permutations(av[1], 0);
	return (0);
}
