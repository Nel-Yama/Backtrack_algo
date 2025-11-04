/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:35:18 by nel-yama          #+#    #+#             */
/*   Updated: 2025/11/04 19:35:18 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_sub_set(int *s, int *sub_s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (sub_s[i] == 1)
		{
			if (i == len - 1)
				printf("%d", s[i]);
			else
				printf("%d ", s[i]);
		}
		i++;
	}
	printf("\n");
}

void	ft_powerset(int *s, int *sub_s, int n, int sum, int idx, int len)
{
	if (idx == len)
	{
		if (sum == n)
			print_sub_set(s, sub_s, len);
		return ;
	}
	if (sum > n)
		return ;
	sub_s[idx] = 1;
	ft_powerset(s, sub_s, n, sum + s[idx], idx + 1, len);
	sub_s[idx] = 0;
	ft_powerset(s, sub_s, n, sum, idx + 1, len);
}

int	main(int ac, char **av)
{
	int	n;
	int	*s;
	int	*sub_s;
	int	i;


	if (ac < 2)
		return (1);
	n = atoi(av[1]);
	s = malloc((ac - 2) * sizeof(int));
	sub_s = calloc(ac - 2, sizeof(int));
	if (!s || !sub_s)
		return (1);
	i = 0;
	while (i < ac - 2)
	{
		s[i] = atoi(av[i + 2]);
		i++;
	}
	ft_powerset(s, sub_s, n, 0, 0, ac - 2);
	free(s);
	free(sub_s);
	return(0);
}
