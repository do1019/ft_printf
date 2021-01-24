/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 03:27:27 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 03:45:41 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_p(char ***fmt, va_list *args, t_flags *flags)
{
	char		*ptr;
	char		*tmp;
	int			count;
	int			output_count;

	if (!(tmp = ft_ullitoa(va_arg(*args, unsigned long long int), true)))
		return (ERROR);
	output_count = 0;
	if ((flags)->precision_switch || (flags)->zero_padding)
		if (convert_num_with_flags_info(flags, &tmp, false) == ERROR)
			return (ERROR);
	ptr = ft_strjoin("0x", tmp);
	SAFE_FREE(tmp);
	if (!ptr)
		return (ERROR);
	count = ft_strlen(ptr);
	if ((flags)->left_justified == true)
		output_count += output_left_justified(flags, ptr, count);
	else if ((flags)->field_width_switch == true)
		output_count += output_field_width(flags, ptr, count);
	else
		output_count += write(1, ptr, count);
	SAFE_FREE(ptr);
	(**fmt)++;
	return (output_count);
}

int	output_hex(char ***fmt, va_list *args, t_flags *flags)
{
	char	*ptr;
	int		count;
	int		output_count;

	if (**fmt[0] == 'X')
		ptr = ft_uitoa(va_arg(*args, unsigned int), true, true);
	else
		ptr = ft_uitoa(va_arg(*args, unsigned int), true, false);
	if (!ptr)
		return (ERROR);
	output_count = 0;
	if ((flags)->precision_switch || (flags)->zero_padding)
		if (convert_num_with_flags_info(flags, &ptr, false) == ERROR)
			return (ERROR);
	count = ft_strlen(ptr);
	if ((flags)->left_justified == true)
		output_count += output_left_justified(flags, ptr, count);
	else if ((flags)->field_width_switch == true)
		output_count += output_field_width(flags, ptr, count);
	else
		output_count += write(1, ptr, count);
	SAFE_FREE(ptr);
	(**fmt)++;
	return (output_count);
}
