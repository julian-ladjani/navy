/*
** prog.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sat Feb 11 00:10:08 2017 julian ladjani
** Last update Wed Feb 15 05:27:24 2017 julian ladjani
*/

#include "navy.h"

void	my_turn()
{
  char	*pos;
  int	posx;
  int	posy;

  my_printf("attack: ");
  while ((pos = get_next_line(0)) == NULL);
  if (my_strlen(pos) > 1 && pos[0] > 0 && pos[0] < 9 && pos[1] > 0)
    {
      my_printf("wrong position\n");
      my_turn();
    }
  else
    {
      my_printf("%s:", pos);
      start_sender(SENDPOSX);
    }
}

void	his_turn(t_map *map)
{
  my_printf("waiting for enemy's attack...\n");
  while (g_game.poshit[0] == 0 || g_game.poshit[1] == 0);
  if (g_game.poshit[0] < 9 && g_game.poshit[1] < 9)
    {
      if (is_num(map->map[g_game.poshit[1]][g_game.poshit[0]]))
        {
	  my_printf("%s: hit\n", "sended_pos()");
          start_sender(SENDHIT);
        }
      else
	{
	  my_printf("%s: missed\n", "sended_pos()");
	  start_sender(SENDHIT);
	}
    }
  else
    {
      my_printf("ERROR: wrong\n");
      start_sender(SENDHIT);
    }
  g_game.poshit[0] = 0;
  g_game.poshit[1] = 0;
}

void	the_navy_game(t_map *map)
{
  his_turn(map);
  my_turn();
}

int	the_game_loop(t_map *map)
{
  int	value;
  while ((value = check_victory(map)) == 0)
    the_navy_game(map);
  return (value);
}
