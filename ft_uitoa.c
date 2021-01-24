/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 02:08:09 by dogata            #+#    #+#             */
/*   Updated: 2020/08/18 16:20:32 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	count_digit(unsigned int num, int *digit, bool hex)
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

static void	branch(int *div, int *upper_lower, bool hex, bool upper)
{
	if (hex == true)
		*div = 16;
	else
		*div = 10;
	if (hex == true && upper == true)
		*upper_lower = 55;
	else if (hex == true && upper == false)
		*upper_lower = 87;
}

static char	*convert_uitoa(unsigned int num, char *str, bool hex, bool upper)
{
	int	rem;
	int div;
	int digit;
	int upper_lower;

	branch(&div, &upper_lower, hex, upper);
	count_digit(num, &digit, hex);
	while (digit || (hex == true && num != 0))
	{
		rem = num % div;
		if (hex == true)
		{
			if (10 > rem)
				str[digit-- - 1] = rem + 48;
			else
				str[digit-- - 1] = rem + upper_lower;
		}
		else
			str[digit-- - 1] = rem + 48;
		num = num / div;
	}
	return (str);
}

char		*ft_uitoa(unsigned int num, bool hex, bool upper)
{
	char	*str;
	int		digit;

	if (num == 0)
		return (ft_strdup("0"));
	count_digit(num, &digit, hex);
	if (!(str = ft_calloc(digit + 1, sizeof(char))))
		return (NULL);
	return (convert_uitoa(num, str, hex, upper));
}
