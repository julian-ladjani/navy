/*
** parser.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:16:15 2017 Maxime PICOT
** Last update Tue Feb 14 12:50:42 2017 julian ladjani
*/

#include <fcntl.h>
#include "navy.h"

char	**my_setmap()
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((map = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (i < 8)
    {
      if ((map[i] = malloc(sizeof(char) * 9)) == NULL)
	return (NULL);
      while (j < 8)
	{
	  map[i][j] = '.';
	  j++;
	}
      map[i][j] = '\0';
      i++;
      j = 0;
    }
  map[i] = NULL;
  return (map);
}

char 	**nav_parser(char *path)
{
  char	**map;
  int	fd;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  map = my_setmap();
  map = edit_map(map, fd);
  return (map);
}

t_coords	coords_parser(char *line)
{
  t_coords	coords;

  coords = init_coords();
  if (line && my_strlen(line) == 7 && line[1] == ':' && line[4] == ':')
    {
      coords.boat = line[0] - 48;
      my_coords(line[2], line[3], &coords.fx, &coords.fy);
      my_coords(line[5], line[6], &coords.lx, &coords.ly);
    }
  return (coords);
}

char		**edit_map(char **map, int fd)
{
  char		*line;
  int		i;
  t_coords	coords;

  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (i > 4)
	return (NULL);
      coords = coords_parser(line);
      if ((map = coord_in_map(coords, map)) == NULL)
	return (NULL);
      i++;
    }
  if (i < 4)
    return (NULL);
  return (map);
}
