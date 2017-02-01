/*
** navy.h for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy/include
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 15:59:07 2017 julian ladjani
** Last update Wed Feb  1 17:46:20 2017 Maxime PICOT
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
  char		**map;
  int		posx;
  int		posy;
  int		mode;
  pid_t		mpid;
  pid_t		opid;
}		t_game;

typedef struct	s_coords
{
  int		fx;
  int		fy;
  int		lx;
  int		ly;
}

t_game		game;

int		printf(char *str, ...);

#endif /* !NAVY_H_ */
