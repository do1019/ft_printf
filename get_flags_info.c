/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:05:27 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 05:30:50 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'p' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static void	check_left_and_zero(char ****fmt, t_flags *flags)
{
	while (***fmt[0] == '-' || ***fmt[0] == '0')
	{
		if (***fmt[0] == '-')
			(flags)->left_justified = true;
		else if (***fmt[0] == '0' && ((flags)->left_justified != true))
			(flags)->zero_padding = true;
		(***fmt)++;
	}
}

static void	check_fieldwidth(char ****fmt, t_flags *flags, va_list *args)
{
	if (***fmt[0] == '*')
	{
		(flags)->field_width_switch = true;
		if (((flags)->field_width = va_arg(*args, int)) < 0)
		{
			(flags)->field_width *= -1;
			(flags)->left_justified = true;
			(flags)->zero_padding = false;
		}
		(***fmt)++;
	}
	else if (ft_isdigit(***fmt[0]))
	{
		(flags)->field_width_switch = true;
		while (ft_isdigit(***fmt[0]))
		{
			(flags)->field_width = (flags)->field_width * 10 + ***fmt[0] - 48;
			(***fmt)++;
		}
	}
	else if (!is_conversion(***fmt[0]) && ***fmt[0] != '.')
		(flags)->format_error = true;
}

static void	check_precision(char ****fmt, t_flags *flags, va_list *args)
{
	if (***fmt[0] == '.')
	{
		(flags)->precision_switch = true;
		(***fmt)++;
		if (***fmt[0] == '*')
		{
			if (((flags)->precision = va_arg(*args, int)) < 0)
				(flags)->precision_switch = false;
			(***fmt)++;
		}
		else if (ft_isdigit(***fmt[0]))
		{
			while (ft_isdigit(***fmt[0]))
			{
				(flags)->precision = (flags)->precision * 10 + ***fmt[0] - 48;
				(***fmt)++;
			}
		}
		else if (is_conversion(***fmt[0]))
			(flags)->precision = 0;
		else if (!is_conversion(***fmt[0]))
			(flags)->format_error = true;
	}
}

t_flags		*get_flags_info(char ***fmt, va_list *args)
{
	t_flags *flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	*flags = (t_flags){false};
	check_left_and_zero(&fmt, flags);
	check_fieldwidth(&fmt, flags, args);
	check_precision(&fmt, flags, args);
	if (!is_conversion(**fmt[0]))
		flags->format_error = true;
	return (flags);
}
