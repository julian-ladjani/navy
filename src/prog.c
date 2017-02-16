/*
** prog.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sat Feb 11 00:10:08 2017 julian ladjani
** Last update Thu Feb 16 01:41:17 2017 julian ladjani
*/

#include "navy.h"

char	*sended_pos(int posx, int posy)
{
  char	*pos;

  pos = malloc(3 * sizeof(char));
  my_printf("%d\n", posx);
  pos[0] = my_convertcoords(posx, 2);
  pos[1] = posy + 48;
  pos[2] = '\0';
  return (pos);
}

int	check_getpos(char posx, char posy)
{
  if (posx >= 'A' && posx <= 'H'
      && posy > '0' && posy < '9')
    return (0);
  return (1);
}

void	check_hit(t_map *map, char *pos)
{
  int	posx;
  int	posy;

  while (g_game.mode != NONE);
  if (my_strlen(pos) == 2 &&
      check_getpos(pos[0], pos[1]) == 0)
    {
      posx = my_convertcoords(pos[0], 1) - 48 - 1;
      posy = pos[1] - 48 - 1;
      if (g_game.poshit[2] == 1)
        {
          map->omap[posy][posx] = 'x';
          my_printf("%s: hit\n\n", pos);
        }
      else if (g_game.poshit[2] == 2)
        {
          if (map->omap[posy][posx] != 'x')
            map->omap[posy][posx] = '0';
          my_printf("%s: missed\n\n", pos);
        }
      else
	my_printf("%s: wrong\n\n", pos);
    }
}

char	*my_turn(t_map *map)
{
  char	*pos;

  my_printf("attack: \e[3m");
  while ((pos = get_next_line(0)) == NULL);
  my_printf("\e[0m");
  if (my_strlen(pos) == 2 &&
      check_getpos(pos[0], pos[1]) == 0)
    {
      g_game.poshit[0] = my_convertcoords(pos[0], 1) - 48;
      g_game.poshit[1] = pos[1] - 48;
      start_sender(SENDPOSX, 0);
    }
  else
    {
      my_printf("wrong position\n");
      my_turn(map);
    }
  return (pos);
}

void	his_turn(t_map *map)
{
  write_play(map->map, map->omap);
  my_printf("waiting for enemy's attack...\n");
  while (g_game.mode != NONE);
  if (check_getpos(my_convertcoords(g_game.poshit[0], 2),
		   g_game.poshit[1] + 48) == 0)
    {
      if (is_num(map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1]))
        {
	  map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = 'x';
	  my_printf("%s: hit\n\n", sended_pos(g_game.poshit[0], g_game.poshit[1]));
          start_sender(SENDHIT, 1);
        }
      else
	{
	  if (map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] != 'x')
	    map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = '0';
	  my_printf("%s: missed\n\n", sended_pos(g_game.poshit[0], g_game.poshit[1]));
	  start_sender(SENDHIT, 2);
	}
    }
  else
    {
      my_printf("ERROR: wrong\n\n");
      start_sender(SENDHIT, 3);
    }
}
