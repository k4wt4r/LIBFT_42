/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-alam <kel-alam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:39:14 by kel-alam          #+#    #+#             */
/*   Updated: 2021/11/11 16:32:49 by kel-alam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i_dst;
	size_t	j_src;

	i_dst = 0;
	j_src = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (len_src + size);
	i_dst = len_dst;
	while (src[j_src] && (i_dst + j_src < size - 1))
	{
		dst[i_dst + j_src] = src[j_src];
		j_src++;
	}
	dst[i_dst + j_src] = '\0';
	return (len_dst + len_src);
}
