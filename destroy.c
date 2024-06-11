/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:46:30 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/09 11:46:44 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

void	destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

void	destroy_window(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	destroy_mlx(mlx);
}

void	destroy_image(void *mlx, void *win, void *img)
{
	mlx_destroy_image(mlx, img);
	destroy_window(mlx, win);
}
