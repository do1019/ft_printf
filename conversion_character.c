/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:09:13 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 03:44:43 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_character(char **fmt, va_list *args)
{
	t_flags	*flags;
	char	*tmp;
	int		output_count;

	tmp = *fmt;
	(*fmt)++;
	if (!(flags = get_flags_info(&fmt, args)))
		return (ERROR);
	if (flags->format_error == true)
		return (format_error(&fmt, &tmp));
	if (*fmt[0] == 'c' || *fmt[0] == '%')
		output_count = output_c(&fmt, args, flags);
	else if (*fmt[0] == 's')
		output_count = output_s(&fmt, args, flags);
	else if (*fmt[0] == 'd' || *fmt[0] == 'i')
		output_count = output_int(&fmt, args, flags);
	else if (*fmt[0] == 'u')
		output_count = output_u_int(&fmt, args, flags);
	else if (*fmt[0] == 'x' || *fmt[0] == 'X')
		output_count = output_hex(&fmt, args, flags);
	else
		output_count = output_p(&fmt, args, flags);
	SAFE_FREE(flags);
	return (output_count);
}

int	format_error(char ***fmt, char **tmp)
{
	int output_count;
	int i;

	output_count = **fmt - *tmp;
	i = 0;
	while (output_count > i)
	{
		write(1, (*tmp)++, 1);
		i++;
	}
	return (output_count);
}
