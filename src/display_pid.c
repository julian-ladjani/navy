/*
** display_pid.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Wed Feb  1 12:01:39 2017 Maxime PICOT
** Last update Sun Feb 19 23:19:12 2017 julian ladjani
*/

#include <sys/types.h>
#include <unistd.h>
#include "navy.h"

void	display_pid()
{
  pid_t	p;

  p = getpid();
  my_printf("my_pid: %d\n", p);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
