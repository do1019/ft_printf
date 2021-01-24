/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_csidu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 02:22:04 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 03:19:06 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_c(char ***fmt, va_list *args, t_flags *flags)
{
	char	c;
	int		output_count;

	if (**fmt[0] == '%')
		c = '%';
	else
		c = va_arg(*args, int);
	if ((flags)->left_justified == true)
		output_count = output_left_justified(flags, &c, 1);
	else if ((flags)->field_width_switch == true)
		output_count = output_field_width(flags, &c, 1);
	else
		output_count = write(1, &c, 1);
	(**fmt)++;
	return (output_count);
}

int	output_s(char ***fmt, va_list *args, t_flags *flags)
{
	char	*s;
	int		count;
	int		output_count;

	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	count = ft_strlen(s);
	if ((flags)->precision_switch == true && (flags)->precision <= count)
		count = (flags)->precision;
	if ((flags)->left_justified == true)
		output_count = output_left_justified(flags, s, count);
	else if ((flags)->field_width_switch == true)
		output_count = output_field_width(flags, s, count);
	else
		output_count = write(1, s, count);
	(**fmt)++;
	return (output_count);
}

int	output_int(char ***fmt, va_list *args, t_flags *flags)
{
	char	*num;
	int		count;
	int		output_count;
	int		negative;

	if (!(num = ft_itoa(va_arg(*args, int))))
		return (ERROR);
	negative = false;
	output_count = 0;
	if (num[0] == '-')
		negative = true;
	if ((flags)->precision_switch || (flags)->zero_padding)
		if (convert_num_with_flags_info(flags, &num, negative) == ERROR)
			return (ERROR);
	count = ft_strlen(num);
	if ((flags)->left_justified == true)
		output_count += output_left_justified(flags, num, count);
	else if ((flags)->field_width_switch == true)
		output_count += output_field_width(flags, num, count);
	else
		output_count += write(1, num, count);
	SAFE_FREE(num);
	(**fmt)++;
	return (output_count);
}

int	output_u_int(char ***fmt, va_list *args, t_flags *flags)
{
	char	*num;
	int		count;
	int		output_count;

	if (!(num = ft_uitoa(va_arg(*args, unsigned int), false, NULL)))
		return (ERROR);
	output_count = 0;
	if ((flags)->precision_switch || (flags)->zero_padding)
		if (convert_num_with_flags_info(flags, &num, false) == ERROR)
			return (ERROR);
	count = ft_strlen(num);
	if ((flags)->left_justified == true)
		output_count += output_left_justified(flags, num, count);
	else if ((flags)->field_width_switch == true)
		output_count += output_field_width(flags, num, count);
	else
		output_count += write(1, num, count);
	SAFE_FREE(num);
	(**fmt)++;
	return (output_count);
}
