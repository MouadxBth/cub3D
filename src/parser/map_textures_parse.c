/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:30:46 by mnadir            #+#    #+#             */
/*   Updated: 2023/06/23 18:18:59 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_vector.h"

static void	ft_set_textures(char c, char *str, t_map *cub)
{
	if (c == 'N' && !cub->north_wall_texture)
		cub->north_wall_texture = str;
	else if (c == 'S' && !cub->south_wall_texture)
		cub->south_wall_texture = str;
	else if (c == 'E' && !cub->east_wall_texture)
		cub->east_wall_texture = str;
	else if (c == 'W' && !cub->west_wall_texture)
		cub->west_wall_texture = str;
	else
		ft_yell_err("Duplicates Detected.", cub->f_lines);
}

static void	ft_type_check(char *s, t_map *cub)
{
	if (ft_isspace(*(s + 1)) || !ft_isspace(*(s + 2)))
		ft_yell_err("Unknown Element.", cub->f_lines);
	else if ((*s == 'S' || *s == 'N') && *(s + 1) != 'O')
		ft_yell_err("Unknown Element.", cub->f_lines);
	else if (*s == 'E' && *(s + 1) != 'A')
		ft_yell_err("Unknown Element.", cub->f_lines);
	else if (*s == 'W' && *(s + 1) != 'E')
		ft_yell_err("Unknown Element.", cub->f_lines);
}

void	ft_resolve_textures(char *s, t_map *cub)
{
	char	c;
	char	*str;
	int		len;
	int		fd;

	c = *s;
	ft_type_check(s, cub);
	s = s + 2;
	while (*s && ft_isspace(*s))
		s++;
	if (!*s)
		ft_yell_err("No path to texture.", cub->f_lines);
	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	ft_check(&str, s, len);
	s += len;
	while (*s && ft_isspace(*s))
		s++;
	if (*s)
		ft_yell_err("Unknown Element.", cub->f_lines);
	fd = open(str, O_RDWR);
	if (fd < 0)
		ft_yell_err("Invalid path to texture.", cub->f_lines);
	(ft_set_textures(c, str, cub), close(fd));
}

static void	ft_rgb_check(char *s, int *rgb, int inx, t_map *cub)
{
	int		len;
	char	*num;

	while (inx < 3 && *s)
	{
		len = 0;
		while (s[len] && !ft_isspace(s[len]) && s[len] != ',')
			len++;
		num = ft_strndup(s, len);
		if (!num)
			ft_yell_err("Allocation Err.", cub->f_lines);
		while (*num)
			if ((*num > '9' || *(num++) < '0'))
				(ft_yell_err("Wrong color.", cub->f_lines), free(num));
		num -= len;
		rgb[inx] = ft_atoi(num);
		if ((rgb[inx] < 0 || rgb[inx] > 255) || len > 3)
			(ft_yell_err("Wrong color.", cub->f_lines), free(num));
		s += len;
		while (*s && ((ft_isspace(*s) || *s == ',')))
			s++;
		(free(num), inx++);
	}
	if (inx < 2 || *s)
		ft_yell_err("Unknown Element.", cub->f_lines);
}

void	ft_resolve_floorceiling(char *s, t_map *cub)
{
	int		rgb[3];
	char	c;
	int		count;

	c = *s;
	if (!ft_isspace(*(s + 1)))
		ft_yell_err("Unknown Element.", cub->f_lines);
	s++;
	while (*s && ft_isspace(*s))
		s++;
	if (!*s)
		ft_yell_err("No RGB colors.", cub->f_lines);
	count = ft_count_chars(s, ',');
	if (count <= 0 || count > 2)
		ft_yell_err("Invalid RGB Colors.", cub->f_lines);
	ft_rgb_check(s, rgb, 0, cub);
	if (c == 'F' && cub->floor_color[0] == -1)
		ft_memcpy(cub->floor_color, rgb, sizeof(rgb));
	else if (c == 'C' && cub->ceiling_color[0] == -1)
		ft_memcpy(cub->ceiling_color, rgb, sizeof(rgb));
	else
		ft_yell_err("Duplicates Detected.", cub->f_lines);
}
