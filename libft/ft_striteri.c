/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:17:40 by houssana          #+#    #+#             */
/*   Updated: 2017/04/20 15:15:59 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int i2;

	i2 = 0;
	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		while (i2 < i)
		{
			f(i2, s);
			i2++;
			s++;
		}
	}
}
