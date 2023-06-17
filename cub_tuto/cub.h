/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:16:31 by oidboufk          #+#    #+#             */
/*   Updated: 2023/06/17 19:00:05 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB
#define CUB
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_global {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	imgs[3];
}	t_global;


#define WIDTH 1664
#define HEIGHT 720

void	ft_put_pixel(t_img *img, unsigned int x, unsigned int y, int color);
void	init(t_global *g, t_img *img);
#endif