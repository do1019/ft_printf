/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:47:43 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 05:35:40 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf(const char *format, va_list *args)
{
	int		ans;
	int		output_count;
	char	*fmt;

	ans = 0;
	fmt = (char *)format;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if ((output_count = conversion_character(&fmt, args)) == ERROR)
				return (ERROR);
			ans += output_count;
		}
		else
		{
			write(1, fmt, 1);
			fmt++;
			ans++;
		}
	}
	return (ans);
}

int			ft_printf(const char *format, ...)
{
	int		ans;
	va_list	args;

	va_start(args, format);
	ans = ft_vprintf(format, &args);
	va_end(args);
	return (ans);
}
