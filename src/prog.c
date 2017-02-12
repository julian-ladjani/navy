/*
** prog.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sat Feb 11 00:10:08 2017 julian ladjani
** Last update Sun Feb 12 00:44:27 2017 julian ladjani
*/

void	my_turn()
{
  char	*pos;
  int	posx;
  int	posy;

  my_printf("attack: ");
  while ((pos == my_getnextline(0)) == NULL);
  if (wrong)
    {
      my_printf("wrong position\n");
      my_turn();
    }
  else
    {
      my_printf("%s:", pos);
      send_pos(posx, posy);
    }
}

void	his_turn(t_map *map)
{
OB  my_printf("waiting for enemy's attack...\n");
  while (game.poshit[0] == 0 || game.poshit[1] == 0);
  if (game.poshit[0] < 9 && game.poshit[1] < 9)
    {
      if (isnumber(map->map[game.poshit[1]][game.poshit[0]]))
        {
	  my_printf("%s: hit\n", sended_pos());
          send_hit(1);
        }
      else
	{
	  my_printf("%s: missed\n", sended_pos());
	  send_hit(2);
	}
    }
  else
    {
      my_printf("ERROR: wrong\n");
      send_hit(3);
    }
  game.poshit[0] = 0;
  game.poshit[1] = 0;
}

void	the_navy_game(t_map *map)
{
  his_turn(map);
  my_turn();
}

int	the_game_loop(t_map *map)
{
  int	value;
  while ((value = check_victory) == 0)
    the_navy_game(map);
  return (value);
}
