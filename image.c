/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:42:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 10:54:11 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "library.h"

static int	image_pixel_in_bounds(int x, int y)
{
	return (x >= 0 && x < SCREEN && y >= 0 && y < SCREEN);
}

unsigned int	*image_pixel_at(void *img, int x, int y)
{
	int				bpp;
	int				line;
	int				endian;
	unsigned int	*addr;

	if (!img || !image_pixel_in_bounds(x, y))
		return (NULL);
	addr = (unsigned int *)mlx_get_data_addr(img, &bpp, &line, &endian);
	return (&addr[x + y * SCREEN]);
}
