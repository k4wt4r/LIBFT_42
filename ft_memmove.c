/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-alam <kel-alam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:49:07 by kel-alam          #+#    #+#             */
/*   Updated: 2021/11/11 16:19:12 by kel-alam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			tmp[i] = *(char *)(src + i);
			i++;
		}
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = tmp[i];
			i++;
		}
		free (tmp);
	}
	return (dst);
}
