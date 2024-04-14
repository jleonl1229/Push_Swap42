/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:26 by jleon-la          #+#    #+#             */
/*   Updated: 2023/12/21 15:21:57 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*destination;
	unsigned char		*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	if (destination > source)
	{
		while (len--)
			((char *)destination)[len] = ((char *)source)[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[15] = "012345678901";
	char	src[15] = "012345678901";

	printf("%s", ft_memmove(dst, src, 15));
	printf("\nOriginal: %s", memmove(dst, src, 15));
	return (0);
}*/
