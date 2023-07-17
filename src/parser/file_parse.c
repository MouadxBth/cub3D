/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:17:14 by mnadir            #+#    #+#             */
/*   Updated: 2023/06/23 18:58:53 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

void	ft_extension_check(char *file, char *ext)
{
	char	*extension;

	if (!file)
		ft_yell_err("Not the correct file extension.", NULL);
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strlen(extension) != ft_strlen(ext)
		|| ft_strncmp(extension, ext, ft_strlen(ext)))
		ft_yell_err("Not the correct file extension.", NULL);
	return ;
}

char	**ft_dump_file(int fd)
{
	char	**f_content;
	char	*line;
	char	*tmp;

	f_content = (char **)get_next_line(fd);
	while ((char *)f_content)
	{
		tmp = (char *)f_content;
		line = get_next_line(fd);
		if (!line)
			break ;
		f_content = (char **)ft_strjoin((char *)f_content, line);
		(free(line), free(tmp));
	}
	tmp = (char *)f_content;
	f_content = ft_split((char *)f_content, '\n');
	if (!f_content)
		return (free(tmp), ft_yell_err("File is empty", NULL), NULL);
	return (free(tmp), f_content);
}

char	**ft_open_file(char *file)
{
	char	**file_content;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (perror("open"), exit(EXIT_FAILURE), NULL);
	file_content = ft_dump_file(fd);
	close(fd);
	return (file_content);
}

void	ft_parse_file(char **f_lines, int *inx, t_map *cub)
{
	int		jnx;
	char	c;

	jnx = 0;
	while (f_lines[*inx][jnx] && ft_isspace(f_lines[*inx][jnx]))
		jnx++;
	if (!f_lines[*inx][jnx] && ++(*inx))
		return ;
	c = f_lines[*inx][jnx];
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		ft_resolve_textures(&f_lines[*inx][jnx], cub);
	else if (c == 'F' || c == 'C')
		ft_resolve_floorceiling(&f_lines[*inx][jnx], cub);
	else if (c == '1')
	{
		ft_resolve_map(f_lines + *inx, cub);
		while (f_lines[*inx])
			(*inx)++;
		return ;
	}
	else
		ft_yell_err("Unknown Element.", cub->f_lines);
	(*inx)++;
}

void	ft_map(char *file, t_map *map)
{
	int			inx;
	static int	def[3];

	def[0] = -1;
	def[1] = -1;
	def[2] = -1;
	if (!map || !file || ft_strlen(file) <= 0)
		return ;
	map->north_wall_texture = NULL;
	map->south_wall_texture = NULL;
	map->west_wall_texture = NULL;
	map->east_wall_texture = NULL;
	ft_memcpy(map->floor_color, def, sizeof(def));
	ft_memcpy(map->ceiling_color, def, sizeof(def));
	map->matrix = NULL;
	map->f_lines = ft_open_file(file);
	inx = 0;
	while (map->f_lines[inx])
		ft_parse_file(map->f_lines, &inx, map);
	if (!ft_map_elems_check(map, 1))
		ft_yell_err("Some elements are missing.", map->f_lines);
}
