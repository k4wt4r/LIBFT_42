/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-alam <kel-alam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:59:20 by kel-alam          #+#    #+#             */
/*   Updated: 2021/11/16 08:22:10 by kel-alam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 1;
	if (n < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		count += 1;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (number_len(n)));
	if (!str)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[number_len(n) - i++] = '\0';
	while (nbr >= 10)
	{
		str[number_len(n) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[number_len(n) - i++] = (nbr % 10) + '0';
	return (str);
}
