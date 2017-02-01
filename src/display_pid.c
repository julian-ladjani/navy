/*
** display_pid.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Wed Feb  1 12:01:39 2017 Maxime PICOT
** Last update Wed Feb  1 12:05:23 2017 Maxime PICOT
*/

#include <sys/types.h>
#include <unistd.h>
#include "navy.h"

void	display_pid()
{
  pid_t	p;
  
  p = getpid();
  my_printf("my_pid:  %i\n", p);
}
