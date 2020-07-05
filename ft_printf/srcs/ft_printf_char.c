/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:41:03 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/18 16:34:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_char(t_printf *count, va_list *ap)
{
	int		nb;
	char	c;

	nb = 1;
	count->flag_is_c_0 = 0;
	if ((c = (char)va_arg(*ap, int)) == '\0')
		count->flag_is_c_0 = 1;
	ft_write_buffer_c(count, c);
	return (1);
}
