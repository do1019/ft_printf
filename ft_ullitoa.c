/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 01:41:20 by dogata            #+#    #+#             */
/*   Updated: 2020/08/20 03:08:48 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	count_digit(unsigned long long int num, int *digit, bool hex)
{
	int div;

	*digit = 0;
	if (hex == true)
		div = 16;
	else
		div = 10;
	while (num != 0)
	{
		num = num / div;
		(*digit)++;
	}
}

static void	branch(int *div, bool hex)
{
	if (hex == true)
		*div = 16;
	else
		*div = 10;
}

static char	*convert_ullitoa(unsigned long long int num, char *str, bool hex)
{
	long long int	rem;
	int				div;
	int				digit;

	branch(&div, hex);
	count_digit(num, &digit, hex);
	while (digit || (hex == true && num != 0))
	{
		rem = num % div;
		if (hex == true)
		{
			if (10 > rem)
				str[digit-- - 1] = rem + 48;
			else
				str[digit-- - 1] = rem + 87;
		}
		else
			str[digit-- - 1] = rem + 48;
		num = num / div;
	}
	return (str);
}

char		*ft_ullitoa(unsigned long long int num, bool hex)
{
	char	*str;
	int		digit;

	if (num == 0)
		return (ft_strdup("0"));
	count_digit(num, &digit, hex);
	if (!(str = ft_calloc(digit + 1, sizeof(char))))
		return (NULL);
	return (convert_ullitoa(num, str, hex));
}
