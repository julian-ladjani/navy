/*
** navy.h for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy/include
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 15:59:07 2017 julian ladjani
** Last update Wed Feb 15 22:45:06 2017 julian ladjani
*/

#ifndef NAVY_H_
# define NAVY_H_

#include <stdarg.h>
#include <signal.h>
#include <stdlib.h>

# define READ_SIZE 32

typedef enum	e_mode
  {
    NONE,
    RECPOSX,
    RECPOSY,
    RECHIT,
    SENDPOSX,
    SENDPOSY,
    SENDHIT
  }		t_mode;

typedef struct	s_game
{
  int		*poshit;
  t_mode	mode;
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
  int		boat;
}		t_coords;

t_game		g_game;

void		display_pid();
void		my_coords(char c1, char c2, int *posx, int *posy);
void		write_map(char **map);
void		prepare_my_signal();
void		handler_usr2(int sig, siginfo_t *si, void *unised);
void		handler_usr1(int sig, siginfo_t *si, void *unised);
void		handler_action();
void		start_sender(int type, int value);
void		sender_action();
void		sender_send(int type);
void		sender_changemode();
void		the_navy_game_p2(t_map *map);
void		the_navy_game_p1(t_map *map);
void		my_turn(t_map *map);
void		check_hit(t_map *map);
void		his_turn(t_map *map);


unsigned int	my_getnbru(char *str);

int		my_printf(char *str, ...);
int		my_strlen(char *str);
int		is_alpha(char c);
int		is_num(char c);
int		check_boat(char **map, int boat);
int		check_victory(t_map *maps);
int		check_map(char **map, int min);
int		the_game_loop(t_map *map);
int		the_game(char **map, char **omap);
int		check_getpos(char posx, char posy);

char		my_convertcoords(char coord, int type);
char		*get_next_line(const int fd);
char		*sended_pos(int posx, int posy);
char		**my_setmap();
char		**nav_parser(char *path);
char		**edit_map(char **map, int fd);
char		**coord_in_map(t_coords coords, char **map);
char		**set_map_y(t_coords *coords, char **map);
char		**set_map_x(t_coords *coords, char **map);


t_coords	coords_parser(char *line);
t_coords	init_coords();

#endif /* !NAVY_H_ */
