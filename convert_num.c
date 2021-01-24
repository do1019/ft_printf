/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:33:04 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 05:27:19 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_num_with_flags_info(t_flags *flags, char **num, int negative)
{
	char	*tmp;

	tmp = *num;
	if ((flags)->precision >= (int)ft_strlen(*num))
	{
		if (convert_num(flags, &num, negative, true) == ERROR)
			return (ERROR);
	}
	else if ((flags)->field_width > (int)ft_strlen(*num) &&
			(flags)->precision_switch == false)
	{
		if (convert_num(flags, &num, negative, false) == ERROR)
			return (ERROR);
	}
	else if ((flags)->precision_switch == true && (flags)->precision == 0 &&
			*num[0] == '0' && (int)ft_strlen(*num) == 1)
	{
		if (!(*num = ft_strdup("")))
			return (ERROR);
		SAFE_FREE(tmp);
	}
	(flags)->zero_padding = false;
	return (0);
}

int	convert_num(t_flags *flags, char ***num, int negative, bool route)
{
	char *tmp;

	tmp = **num;
	if (route == true)
		**num = ft_calloc(((flags)->precision + 1 + negative), sizeof(char));
	else
		**num = ft_calloc(((flags)->field_width + 1), sizeof(char));
	if (!**num)
		return (ERROR);
	if (negative == true)
		**num[0] = '-';
	if (route == true)
		ft_memset(**num + negative, '0', (flags)->precision - ft_strlen(tmp)
		+ negative);
	else
		ft_memset(**num + negative, '0', (flags)->field_width - ft_strlen(tmp));
	if (route == true)
		ft_strlcat(**num + negative + (flags)->precision - ft_strlen(tmp),
		tmp + negative, ft_strlen(tmp) + 1);
	else
		ft_strlcat(**num + negative + (flags)->field_width - ft_strlen(tmp),
		tmp + negative, ft_strlen(tmp) + 1);
	SAFE_FREE(tmp);
	return (0);
}
