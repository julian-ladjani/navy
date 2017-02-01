/*
** parser.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:16:15 2017 Maxime PICOT
** Last update Wed Feb  1 18:00:35 2017 Maxime PICOT
*/

char	**my_setmap()
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (i < 9)
    {
      if ((map[i] = malloc(sizeof(char) * 9)) == NULL)
	return (NULL);
      while (j < 9)
	{
	  map[i][j] = '.';
	  j++;
	}
      map[i][j] = '\0';
      i++;
      j = 0;
    }
  return (map);
}

char 	**nav_parser(char *path)
{
  char	**map;
  int	fd;

  fd = open(path, O_RDONLY);
  map = my_setmap();
  map = edit_map(map, fd);
  return (map)
}

char	**edit_map(char **map, int fd)
{
  char	*line;
  int	i;

  i = 0;
  while ((line = my_getnextline(fd)) != NULL)
    {
      if (i > 8)
	return (NULL);
      parse_my_line(line, map);
      i++;
    }
}
