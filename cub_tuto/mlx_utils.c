/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:59:21 by oidboufk          #+#    #+#             */
/*   Updated: 2023/06/17 16:54:05 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init(t_global *g, t_img *img)
{
	g->imgs[0].img = mlx_new_image(g->mlx, WIDTH, HEIGHT); 
	g->imgs[0].addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);

	mlx_put_image_to_window(g->mlx, g->win, g->imgs[0].img, 0, 0);
}


void	ft_put_pixel(t_img *img, unsigned int x, unsigned int  y, int color)
{
	char	*dst;

	// 0 < x < w | 0 < y < h
	if (x > WIDTH || y > HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
