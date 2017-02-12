/*
** write_game.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Feb 12 00:33:04 2017 julian ladjani
** Last update Sun Feb 12 00:33:45 2017 julian ladjani
*/

void	write_map(char **map)
{
  int	i;

  i = 0;
  my_printf(" |A B C D E F G H\n");
  my_printf("-+---------------\n");
  while (map[i] != NULL)
    {
      my_printf("%d|%s\n", i + 1, map[i]);
      i++;
    }
}

void	write_play(char **map, char **omap)
{
  my_printf("my positions:\n");
  write_map(map);
  my_printf("\n");
  my_printf("enemy's positions:\n");
  write_map(omap);
}
