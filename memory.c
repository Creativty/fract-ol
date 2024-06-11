/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:12:41 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/09 11:14:32 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memory_set(void *region, unsigned int size, unsigned char byte)
{
	unsigned int	i;

	i = 0;
	if (region)
		while (i < size)
			((unsigned  char *)region)[i++] = byte;
	return (region);
}

void	*memory_zero(void *region, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (region)
		while (i < size)
			((unsigned  char *)region)[i++] = '\0';
	return (region);
}
