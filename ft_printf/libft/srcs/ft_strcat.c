/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 13:39:20 by tallaire          #+#    #+#             */
/*   Updated: 2020/05/25 13:39:21 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (dst && dst[j])
		++j;
	while (dst && src && src[i])
	{
		dst[j] = src[i];
		++j;
		++i;
	}
	dst[j] = '\0';
	return (dst);
}
