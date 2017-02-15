/*
** prog.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sat Feb 11 00:10:08 2017 julian ladjani
** Last update Wed Feb 15 22:56:08 2017 julian ladjani
*/

#include "navy.h"

char	*sended_pos(int posx, int posy)
{
  char	*pos;

  pos = malloc(3 * sizeof(char));
  pos[0] = my_convertcoords(posx, 2);
  pos[1] = posy + 48;
  pos[2] = '\0';
  return (pos);
}

int	check_getpos(char posx, char posy)
{
  my_printf("%c %c\n", posx, posy);
  if (posx >= 'A' && posx <= 'H'
      && posy > '0' && posy < '9')
    return (0);
  return (1);
}

void	check_hit(t_map *map)
{
  while (g_game.mode != NONE);
  if (check_getpos(g_game.poshit[0] - 48, g_game.poshit[1] - 48) == 0)
    {
      if (g_game.poshit[2] == 1)
        {
          map->omap[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = 'x';
          my_printf("hit\n");
        }
      else if (g_game.poshit[2] == 2)
        {
          if (map->omap[g_game.poshit[1] - 1][g_game.poshit[0] - 1] != 'x')
            map->omap[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = '0';
          my_printf("missed\n");
        }
    }
}

void	my_turn(t_map *map)
{
  char	*pos;

  my_printf("attack: ");
  while ((pos = get_next_line(0)) == NULL);
  my_printf("%s\n", pos);
  if (my_strlen(pos) == 2 &&
      check_getpos(pos[0], pos[1]) == 0)
    {
      my_printf("%s:", pos);
      start_sender(SENDPOSX, 0);
    }
  else
    {
      my_printf("wrong position\n");
      my_turn(map);
    }
  my_printf("%s: ", pos);
  free(pos);
}

void	his_turn(t_map *map)
{
  my_printf("waiting for enemy's attack...\n");
  while (g_game.mode != NONE);
  if (check_getpos(g_game.poshit[0] - 48, g_game.poshit[1] - 48) == 0)
    {
      if (is_num(map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1]))
        {
	  map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = 'x';
	  my_printf("%s: hit\n", sended_pos(g_game.poshit[0], g_game.poshit[1]));
          start_sender(SENDHIT, 1);
        }
      else
	{
	  if (map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] != 'x')
	    map->map[g_game.poshit[1] - 1][g_game.poshit[0] - 1] = '0';
	  my_printf("%s: missed\n", sended_pos(g_game.poshit[0], g_game.poshit[1]));
	  start_sender(SENDHIT, 2);
	}
    }
  else
    {
      my_printf("ERROR: wrong\n");
      start_sender(SENDHIT, 3);
    }
}
