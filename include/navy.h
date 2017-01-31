/*
** navy.h for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy/include
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 15:59:07 2017 julian ladjani
** Last update Tue Jan 31 16:16:33 2017 julian ladjani
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

typedef struct	s_game
{
	char	**map;
	int	posx;
	int	posy;
	pid_t	mpid;
	pid_t	opid;
}		t_game;

t_game		game;

int		printf(char *str, ...);

#endif /* !NAVY_H_ */
