/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:30:56 by mnadir            #+#    #+#             */
/*   Updated: 2023/06/23 18:59:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

void	fre2d(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_map_elems_check(t_map *cub, int map)
{
	if (!cub->north_wall_texture || !cub->south_wall_texture
		|| !cub->west_wall_texture || !cub->east_wall_texture
		|| cub->floor_color[0] == -1 || cub->ceiling_color[0] == -1)
		return (0);
	else if (map && cub->matrix == NULL)
		return (0);
	else
		return (1);
}

void	ft_yell_err(char *err, char **lines)
{
	printf("Error\n %s\n", err);
	if (lines)
		fre2d(lines);
	exit(EXIT_FAILURE);
}

int	set_int(int *integer, int value)
{
	*integer = value;
	return (1);
}

void	ft_check(char **str, char *src, int length)
{
	char	*extension;
	char	*current;

	current = ft_strndup(src, length);
	if (!current)
	{
		free(current);
		ft_yell_err("Not the correct file extension.", NULL);
	}
	extension = ft_strrchr(current, '.');
	if (!extension || ft_strlen(extension) != ft_strlen(".xpm")
		|| ft_strncmp(extension, ".xpm", ft_strlen(".xpm")))
		ft_yell_err("Not the correct file extension.", NULL);
	*str = current;
}
