/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:16:44 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/18 16:41:52 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compte le nombre de de chaines de charactères à spliter
** à partir de la chaine de caractère [*str] et du caractère [sep].
**
** Renvoie le nombre de chaines de caractères à spliter avec {line}.
*/

static	size_t	ft_nb_line(char const *str, char sep)
{
	size_t	line;

	line = 0;
	while (str && *str && *str == sep)
		str++;
	if (str && *str && *str != sep)
		line++;
	while (str && *str && *str != sep)
		str++;
	if (str && *str && *str == sep)
		line += ft_nb_line(str, sep);
	return (line);
}

/*
** Compte le nombre de charactères de la chaine de caractères à spliter
** à partir de la chaine de caractère [*str].
**
** Renvoie le nombre de caractère de la chaine à spliter avec {i}.
*/

static	size_t	nb_char(char const *str, char sep)
{
	size_t	i;

	i = 0;
	while (str && *(str + i) && *(str + i) != sep)
		i++;
	return (i);
}

/*
** désalloue avec free() la mémoire alloué avec malloc() de la chaine de chaine
** de caractères de [**split] ainsi que les sous-chaines de caractères [*split].
**
** Renvoie (NULL).
*/

static	char	**ft_free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(*(split + i));
		*(split + i) = NULL;
		i--;
	}
	free(split);
	split = NULL;
	return (NULL);
}

/*
** Alloue avec malloc() une chaine de chaine de charactères [**split] obtenue
** en séparant la chaine de charactère [*s] passé en paramettre
** avec le caractère [c] passé en paramettre.
** [**split] ne contient pas de chaines vides.
**
** Renvoie [**split] si :
** - Aucun malloc() n'échoue.
** Sinon :
** Renvoie [NULL] et désalloue avec free() [**split]
** ainsi les chaines de caractères qui lui sont attachées.
*/

char			**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	size_t	nb_line;
	char	**split;

	i = -1;
	nb_line = ft_nb_line(s, c);
	if (!s || !(split = (char **)malloc(sizeof(char *) * (nb_line + 1))))
		return (NULL);
	while (++i < (int)nb_line)
	{
		while (*s == c)
			s++;
		if (!(split[i] = (char *)malloc(sizeof(char) * ((nb_char(s, c) + 1)))))
			return (ft_free_split(split, i));
		j = 0;
		while (*s && *s != c)
		{
			*((*(split + i)) + j++) = *s;
			s++;
		}
		*((*(split + i)) + j) = '\0';
	}
	*(split + i) = NULL;
	return (split);
}
