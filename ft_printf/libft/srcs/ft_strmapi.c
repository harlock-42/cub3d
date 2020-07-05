/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:43:42 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/18 14:21:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	int	i;
	char			*str;

	i = 0;
	if (!f || !s || !(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*(s + i))
	{
		str[i] = (*f)(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
