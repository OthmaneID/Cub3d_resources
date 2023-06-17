/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:42:34 by oidboufk          #+#    #+#             */
/*   Updated: 2023/06/17 17:47:51 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char **get_map(void)
{
	int		fd;
	char	**map;
	char	c;
	int		i;
	int		j;
	int		p;

	i = 0;
	j = 0;
	map = (char **)malloc(16 * sizeof(char *));
	fd = open("map", O_RDWR, 666);
	if (fd == -1)
			perror("error_fd:"), exit(0);
	map[i] = malloc(27);
    while ((p = read(fd, &c, 1), p))
    {
		if (p == -1)
			perror("error"), exit(0);
		if (c == '\n')
		{
			map[i][j] = 0;
			map[++i] = malloc(27);
			j = 0;
			continue ;
		}
		map[i][j++] = c;
    }
	close(fd);
	map[i++][j] = 0;
	map[i] = NULL;
	return (map);
}

void	draw_square(t_img *img, int x, int y, int w, int color) 
{
	int i;
	int j;

	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < w)
			ft_put_pixel(img, x + i, y + j++, color);
		i++;
	}
}


void    generate_view(t_global *g)
{
	void	*imag;
	int		i;
	int		j;
	int color;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				color = 0xffff;
			else if (g->map[i][j] == '0')
				color = 0xffffff;
			else if (g->map[i][j] == 'P')
				color = 0xbf0000;
			draw_square(&g->imgs[0], j++ * 64, i * 64, 63, color);
		}
		i++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->imgs[0].img, 0, 0);
}

int main(void)
{
	t_global *g;
	int i;

	g = malloc(sizeof(t_global));
	i = 0;
	g->map = get_map();
	while (g->map[i])
	{
		printf("%s\n", g->map[i]);
		i++;
	}
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Cub3d");
	init(g, &g->imgs[0]);
	generate_view(g);
	mlx_loop(g->mlx);
}
