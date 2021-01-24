/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:11:13 by dogata            #+#    #+#             */
/*   Updated: 2020/07/22 10:29:20 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int num;
	int mflag;

	num = 0;
	mflag = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
	|| *nptr == '\f' || *nptr == '\r' || *nptr == '\n')
		nptr++;
	if (*nptr == '-')
		mflag = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		num = num + (*nptr - '0');
		nptr++;
		if ('0' <= *nptr && *nptr <= '9')
			num = num * 10;
	}
	if (num != 0)
		return (num * mflag);
	return (0);
}
