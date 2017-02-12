/*
** navy.h for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy/include
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 15:59:07 2017 julian ladjani
** Last update Sun Feb 12 04:40:21 2017 julian ladjani
*/

#ifndef NAVY_H_
# define NAVY_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define READ_SIZE 32

typedef struct	s_game
{
  int		*poshit;
  int		mode;
  pid_t		opid;
}		t_game;

typedef struct	s_map
{
  char		**map;
  char		**omap;
}		t_map;

typedef struct	s_coords
{
  int		fx;
  int		fy;
  int		lx;
  int		ly;
}		t_coords;

t_game		game;

void		display_pid();

int		my_printf(char *str, ...);
int		my_strlen(char *str);
int		is_alpha(char c);
int		is_num(char c);

char		my_convertcoords(char coord, int type);
char		*get_next_line(const int fd);
char		**my_setmap();
char		**setcoordstab();
char		**nav_parser(char *path);
char		**edit_map(char **map, int fd);

t_coords	coords_parser(char *line);

#endif /* !NAVY_H_ */
