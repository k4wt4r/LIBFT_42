/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-alam <kel-alam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:42 by kel-alam          #+#    #+#             */
/*   Updated: 2021/11/04 18:51:19 by kel-alam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*is_find;

	p = (unsigned char *)s;
	is_find = NULL;
	while ((s != NULL) && n--)
	{
		if (*p != (unsigned char)c)
			p++;
		else
		{
			is_find = p;
			break ;
		}
	}
	return (is_find);
}
