/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:49:28 by dogata            #+#    #+#             */
/*   Updated: 2020/08/17 18:00:26 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_space_zero(t_flags *flags, int count)
{
	char	c;
	int		output_count;

	c = ' ';
	output_count = 0;
	if ((flags)->zero_padding == true)
		c = '0';
	while ((flags)->field_width-- > count)
		output_count += write(1, &c, 1);
	return (output_count);
}

int	output_left_justified(t_flags *flags, char *str, int count)
{
	int output_count;

	output_count = write(1, str, count);
	if ((flags)->field_width_switch == true)
		output_count += output_space_zero(flags, count);
	return (output_count);
}

int	output_field_width(t_flags *flags, char *str, int count)
{
	int output_count;

	output_count = output_space_zero(flags, count);
	output_count += write(1, str, count);
	return (output_count);
}
