/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:00:45 by nel-yama          #+#    #+#             */
/*   Updated: 2025/11/04 18:00:45 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	count_p(const char *s, int *op, int *cp)
{
	int	i;

	*op = 0;
	*cp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			(*op)++;
		else if (s[i] == ')')
		{
			if (*op > 0)
				(*op)--;
			else
				(*cp)++;
		}
		i++;
	}
}

void	ft_balance(const char *s, char *buff, int idx, int rem_op, int rem_cp, int op, int cp, int len_s)
{
	if ((idx == len_s) && (rem_op == 0 && rem_cp == 0) && op == cp)
	{
		buff[idx] = '\0';
		puts(buff);
		return ;
	}
	if ((op < cp) || (op - cp > len_s - idx))
		return ;
	if (s[idx] == '(')
	{
		if (rem_op > 0)
		{
			buff[idx] = ' ';
			ft_balance(s, buff, idx + 1, rem_op - 1, rem_cp, op, cp, len_s);
			buff[idx] = '(';
                        ft_balance(s, buff, idx + 1, rem_op, rem_cp, op + 1, cp, len_s);
		}
		else
		{
			buff[idx] = '(';
            ft_balance(s, buff, idx + 1, rem_op, rem_cp, op + 1, cp, len_s);
		}
	}
	else if (s[idx] == ')')
	{
		if (rem_cp > 0)
		{
			buff[idx] = ' ';
			ft_balance(s, buff, idx + 1, rem_op, rem_cp - 1, op, cp, len_s);
			buff[idx] = ')';
			ft_balance(s, buff, idx + 1, rem_op, rem_cp, op, cp + 1, len_s);
		}
		else
		{
			buff[idx] = ')';
			ft_balance(s, buff, idx + 1, rem_op, rem_cp, op, cp + 1, len_s);
		}
	}
	else
	{
		buff[idx] = s[idx];
		ft_balance(s, buff, idx + 1, rem_op, rem_cp, op, cp, len_s);
	}
}

int	main(int ac, char **av)
{
	char	buff[256] = "0";
	int		rem_op;
	int		rem_cp;
	int		len_s;

	if (ac != 2)
		return (1);
	count_p(av[1], &rem_op, &rem_cp);
	len_s = ft_strlen(av[1]);
	ft_balance(av[1], buff, 0, rem_op, rem_cp, 0, 0, len_s);
	return (0);
}
