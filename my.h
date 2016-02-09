#ifndef	_MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		my_putchar(char a);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void		my_error(char *str);

typedef struct game game;
struct game
{
  char	name[100];
  int	*plateau[16]
};

#endif
