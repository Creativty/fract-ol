/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:41:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 11:11:16 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "library.h"

t_state	state_new(void)
{
	t_state	state;

	memory_zero(&state, sizeof(t_state));
	state.zoom = 1.0;
	state.render = 1;
	state.iterations = 96;
	return (state);
}

unsigned int	state_get_pixel_color(t_state *state, int x, int y)
{
	double	_x;
	double	_y;

	_x = (double)x / state->zoom + state->offset.real;
	_y = (double)y / state->zoom + state->offset.imag;
	return (state->render_pixel(state, _x, _y));
}

int	state_render(t_state *state)
{
	int				x;
	int				y;
	unsigned int	*pixel;

	y = 0;
	if (state == NULL)
		return (1);
	while (y < SCREEN)
	{
		x = 0;
		while (x < SCREEN)
		{
			pixel = image_pixel_at(state->img, x, y);
			if (pixel)
				*pixel = state_get_pixel_color(state, x, y);
			else
				return (1);
			x++;
		}
		y++;
	}
	return (mlx_put_image_to_window(state->mlx, state->win, state->img, 0, 0));
}
