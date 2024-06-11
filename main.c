/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 10:59:19 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "library.h"

int	prog_loop(t_state *state)
{
	if (state->render == 1)
		state_render(state);
	state->render = 0;
	return (0);
}

int	prog_load(t_state *state, const char *title)
{
	state->mlx = mlx_init();
	if (!state->mlx)
		return (0);
	state->win = mlx_new_window(state->mlx, SCREEN, SCREEN, (char *)title);
	if (!state->win)
		return (destroy_mlx(state->mlx), 0);
	state->img = mlx_new_image(state->mlx, SCREEN, SCREEN);
	if (!state->img)
		return (destroy_window(state->mlx, state->win), 0);
	return (1);
}

void	prog_hook(t_state *state)
{
	mlx_hook(state->win, KeyPress, KeyPressMask, prog_keypress, state);
	mlx_hook(state->win, DestroyNotify, 0, prog_close, state);
	mlx_hook(state->win, ButtonPress, ButtonPressMask, prog_mousepress, state);
	mlx_loop_hook(state->mlx, prog_loop, state);
}

void	prog_start(t_state *state, int mode, const char **argv)
{
	if (mode == 1)
		state->render_pixel = render_pixel_mandelbrot;
	else if (mode == 2)
	{
		state->render_pixel = render_pixel_julia;
		state->params = complex_new(atof(argv[2]), atof(argv[3]));
	}
	mlx_loop(state->mlx);
}

int	prog_entry(const char **argv, const int mode)
{
	t_state	state;

	state = state_new();
	if (prog_load(&state, argv[1]))
	{
		prog_hook(&state);
		prog_start(&state, mode, argv);
		return (destroy_image(state.mlx, state.win, state.img), 1);
	}
	return (0);
}

int	main(const int argc, const char **argv)
{
	int	mode;

	mode = prog_args(argc, argv);
	if (mode)
		return (prog_entry(argv, mode));
	return (1);
}
